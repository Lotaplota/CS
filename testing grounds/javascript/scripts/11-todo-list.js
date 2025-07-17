let todoList = [];
let todoListHTML = '';

function addTodo() {
  let inputLm = document.querySelector('.js-add-todo-field');
  const todoText = inputLm.value;
  inputLm.value = '';
  todoList.push(todoText);
  
  updateTodoListHTML(todoText);
  sendToPage();
}

function updateTodoListHTML(text) {
  todoListHTML = todoListHTML + `<p>${text}</p>`;
}

function sendToPage() {
  const listLm = document.querySelector('.todo-list-div');
  listLm.innerHTML = todoListHTML;
}