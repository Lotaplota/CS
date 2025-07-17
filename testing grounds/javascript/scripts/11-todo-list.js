let todoList = [{
  name: 'finish this course',
  dueDate: '03-08-2025'
}, {
  name: 'finish the wiki site',
  dueDate: '03-08-2025'
}];
let todoListHTML = '';

for (let i = 0; i < todoList.length; i++) {
  console.log(todoList[i]);
}

function addTodo() {
  const textInputLm = document.querySelector('.js-add-todo-field');
  const todoText = textInputLm.value;
  textInputLm.value = '';

  const dateInputLm = document.querySelector('.js-todo-due-date-field');
  const todoDueDate = dateInputLm.value;
  dateInputLm.value = '';

  todoList.push({name: todoText, dueDate: todoDueDate});
  
  renderTodoList();
}

function generateListHTML() {
  todoListHTML = '';

  for (let i = 0; i < todoList.length; i++)
  {
    const todo = todoList[i];
    todoListHTML += `
      <p>
        ${todo.name}, ${todo.dueDate}
        <button onclick="deleteTodo(${i});">
          Delete
        </button>
      </p>`;
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