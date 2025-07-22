let todoList = [{
  name: 'finish this course',
  dueDate: '03-08-2025'
}, {
  name: 'finish the wiki site',
  dueDate: '03-08-2025'
}];
let todoListHTML = '';

renderTodoList();

for (let i = 0; i < todoList.length; i++) {
  console.log(todoList[i]);
}

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

  for (let i = 0; i < todoList.length; i++)
  {
    const todoObject = todoList[i];
    const { name, dueDate } = todoObject;

    todoListHTML += `
      <div>
        ${name}
      </div>
      <div>
        ${dueDate}
      </div>
      <button onclick="deleteTodo(${i});" class="delete-button">
        Delete
      </button>
      `
  }
}

function deleteTodo(i) {
  todoList.splice(i, 1);
  renderTodoList();
}

function renderTodoList() {
  generateListHTML();

  const listLm = document.querySelector('.todo-list-div');
  listLm.innerHTML = todoListHTML;
}