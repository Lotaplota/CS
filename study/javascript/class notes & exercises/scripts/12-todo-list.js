let todoList = [{
  name: 'finish this course',
  dueDate: '03-08-2025'
}, {
  name: 'finish the wiki site',
  dueDate: '03-08-2025'
}];
let todoListHTML = '';

renderTodoList();

document.querySelector('.js-add-button').addEventListener('click', () => {
  addTodo();
});

function addTodo() {
  const textInputLm = document.querySelector('.js-todo-name-input');
  const name = textInputLm.value;
  textInputLm.value = '';

  const dateInputLm = document.querySelector('.js-due-date-input');
  const dueDate = dateInputLm.value;
  dateInputLm.value = '';

  todoList.push({
    // name: name,
    name,
    // dueDate: dueDate
    dueDate
  });
  
  renderTodoList();
}

function generateListHTML() {
  todoListHTML = '';

  todoList.forEach((todo, index) => {
    const { name, dueDate } = todo;

    todoListHTML += `
      <div>
        ${name}
      </div>
      <div>
        ${dueDate}
      </div>
      <button class="delete-button js-delete-button">
        Delete
      </button>
    `
  })
}

function deleteTodo(i) {
  todoList.splice(i, 1);
  renderTodoList();
}

function renderTodoList() {
  generateListHTML();

  const listLm = document.querySelector('.js-todo-list-div');
  listLm.innerHTML = todoListHTML;

  document.querySelectorAll('.js-delete-button')
    .forEach((deleteButton, index) => {
      deleteButton.addEventListener('click', () => {
        deleteTodo(index);
      })
    });
}