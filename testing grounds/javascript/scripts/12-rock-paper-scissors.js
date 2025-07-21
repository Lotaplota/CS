let score = JSON.parse(localStorage.getItem('score')) || {wins: 0, losses: 0, ties: 0};
// Quite a mess here right? Let's understand
// localStorage.getItem may return a null value if no such item exists
// This would make JSON.parse(null) also return a null value
// Since null is falsy, the attribution of the score variable gets the default value after the ||
// You got this, kid!!!!

updateScoreText();

document.querySelector('.js-rock-button').addEventListener('click', () => {
  console.log('you clicked rock')
  play('rock');
});
document.querySelector('.js-paper-button').addEventListener('click', () => {
  play('paper');
});
document.querySelector('.js-scissors-button').addEventListener('click', () => {
  play('scissors');
});

document.body.addEventListener('keydown', (event) => {
  if (event.key.toLowerCase() === 'r') {
    play('rock');
  } else if (event.key.toLowerCase() === 'p') {
    play('paper');
  } else if (event.key.toLowerCase() === 's') {
    play('scissors');
  } else {
    console.log(event.key);
  }
})

function play(move) {
  const computerMove = pickComputerMove();
  let result = '';
  
  // Computing the results and incrementing the scores
  if (move === computerMove) {
    score.ties++;
    result = 'tie';
  }
  else {
    if (move === 'rock') {
      if (computerMove === 'paper') {
        score.losses++;
        result = 'lost';
      } else if (computerMove === 'scissors') {
        score.wins++;
        result = 'won'
      }
    }
    
    if (move === 'paper') {
      if (computerMove === 'rock') {
        score.wins++;
        result = 'won'
      }
      else if (computerMove === 'scissors') {
        score.losses++;
        result = 'lost';
      }
    }
    
    if (move === 'scissors') {
      if (computerMove === 'rock') {
        score.losses++;
        result = 'lost';
      }
      else if (computerMove === 'paper') {
        score.wins++;
        result = 'won'
      }
    }
  }

  displayMatch(move, computerMove, result);
  updateScoreText();
}

function pickComputerMove () {
  let computerMove = '';
  const rand = Math.random();
  
  if (rand < 1 / 3)
    computerMove = 'rock';
  else if (rand < 2 / 3)
    computerMove = 'paper';
  else
    computerMove = 'scissors';

  return computerMove;
}

function resetScore() {
  score.wins = 0;
  score.losses = 0;
  score.ties = 0;

  localStorage.removeItem('score');
  updateScoreText();
}

function updateScoreText() {
  document.querySelector(".js-score-text")
    .innerHTML = `Wins: ${score.wins}, losses: ${score.losses}, ties: ${score.ties}`;
  localStorage.setItem('score', JSON.stringify(score));
}

function displayMatch(playerMove, computerMove, result) {
  const matchMovesLm = document.querySelector('.js-moves');
  const matchResultLm = document.querySelector('.js-result');

  // Getting the icon from the moves
  const playerMoveIcon = document.getElementById(playerMove).innerText; // Should I use querySelector instead of getElementById?
  const computerMoveIcon = document.getElementById(computerMove).innerText;

  matchMovesLm.innerHTML = `You picked ${playerMoveIcon} and the computer picked ${computerMoveIcon}.`;
  
  if (result === 'won') {
    matchResultLm.innerHTML = 'You won!';
  } else if (result === 'lost') {
    matchResultLm.innerHTML = 'You lost.';
  } else if (result === 'tie') {
    matchResultLm.innerHTML = 'It was a tie.';
  }
}

let isAutoPlaying = false;
let intervalID;

function autoPlay(button) { // I can pass the element itself if I use 'this' on the parameters
  if (!isAutoPlaying) {
    intervalID = setInterval(function() {
      play(pickComputerMove());
    }, 1000);

    // This next bit is entirely experimenting
    isAutoPlaying = true;
    button.classList.add('clicked');
  } else {
    clearInterval(intervalID);
    isAutoPlaying = false;
    button.classList.remove('clicked');
  }
}