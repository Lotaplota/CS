import dayjs from 'https://unpkg.com/supersimpledev@8.5.0/dayjs/esm/index.js';

isWeekend(dayjs());

function isWeekend(dayObject){
  if (dayObject.format('d') === '0' || dayObject.format('d') === '6') 
    console.log('yo is weekend');
  else
    console.log('no weekend imma cry');
}

export default isWeekend;