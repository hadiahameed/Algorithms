import product1Image from 'assets/img/products/product_640-1.jpg';
import product2Image from 'assets/img/products/product_640-2.jpg';
import product3Image from 'assets/img/products/product_640-3.jpg';
import product4Image from 'assets/img/products/product_640-4.jpg';
import product5Image from 'assets/img/products/product_640-5.jpg';
import product6Image from 'assets/img/products/product_640-6.jpg';

import user1Image from 'assets/img/users/100_1.jpg';
import user2Image from 'assets/img/users/100_2.jpg';
import user3Image from 'assets/img/users/100_3.jpg';
import user4Image from 'assets/img/users/100_4.jpg';
import user5Image from 'assets/img/users/100_5.jpg';
import user6Image from 'assets/img/users/100_6.jpg';
import user7Image from 'assets/img/users/100_7.jpg';
import user8Image from 'assets/img/users/100_8.jpg';
import user9Image from 'assets/img/users/100_9.jpg';
import user10Image from 'assets/img/users/100_10.jpg';
import user11Image from 'assets/img/users/100_11.jpg';
import user12Image from 'assets/img/users/100_12.jpg';
import user13Image from 'assets/img/users/100_13.jpg';
import user14Image from 'assets/img/users/100_14.jpg';

export const productsData = [
  {
    id: 1,
    image: product1Image,
    title: 'Admin Template',
    description: 'Responsive admin template...',
    right: '$36',
  },
  {
    id: 2,
    image: product2Image,
    title: 'Schedule App',
    description: 'Manage your schedule...',
    right: '$9',
  },
  {
    id: 3,
    image: product3Image,
    title: 'Chat App',
    description: 'Realtime chat application...',
    right: '$12',
  },
  {
    id: 4,
    image: product4Image,
    title: 'Wordpress Business Theme',
    description: 'Over 100+ templates and pages...',
    right: '$24',
  },
  {
    id: 5,
    image: product5Image,
    title: 'Camera App',
    description: 'Over 30+ filter...',
    right: '$6.99',
  },
  {
    id: 6,
    image: product6Image,
    title: 'Calendar App',
    description: 'Organize your schedule...',
    right: '$0.99',
  },
];

export const avatarsData = [
  {
    avatar: user1Image,
    name: 'Tom',
    date: '3 month ago',
  },
  {
    avatar: user2Image,
    name: 'Jenny',
    date: '1 year ago',
  },
  {
    avatar: user3Image,
    name: 'Sim',
    date: '2 hour ago',
  },
  {
    avatar: user4Image,
    name: 'Christine',
    date: 'a month ago',
  },
  {
    avatar: user5Image,
    name: 'Bread',
    date: '6 months ago',
  },
  {
    avatar: user6Image,
    name: 'Dan',
    date: '2 years ago',
  },
  {
    avatar: user7Image,
    name: 'Merry',
    date: '3 month ago',
  },
  {
    avatar: user8Image,
    name: 'John',
    date: '1 month ago',
  },
  {
    avatar: user9Image,
    name: 'Shane',
    date: '7 month ago',
  },
  {
    avatar: user10Image,
    name: 'Star',
    date: '1 year ago',
  },
  {
    avatar: user11Image,
    name: 'Jenny',
    date: '3 month ago',
  },
  {
    avatar: user12Image,
    name: 'Park',
    date: '4 month ago',
  },
  {
    avatar: user13Image,
    name: 'Dave',
    date: '9 month ago',
  },
  {
    avatar: user14Image,
    name: 'Jackson',
    date: '10 month ago',
  },
];

export const userProgressTableData = [
  {
    avatar: user1Image,
    name: 'Tom',
    date: '3 month ago',
    progress: 75,
  },
  {
    avatar: user2Image,
    name: 'Jenny',
    date: '1 year ago',
    progress: 60,
  },
  {
    avatar: user3Image,
    name: 'Sim',
    date: '2 hour ago',
    progress: 50,
  },
  {
    avatar: user4Image,
    name: 'Christine',
    date: 'a month ago',
    progress: 40,
  },
  {
    avatar: user5Image,
    name: 'Bread',
    date: '6 months ago',
    progress: 30,
  },
  {
    avatar: user6Image,
    name: 'Dan',
    date: '2 years ago',
    progress: 25,
  },
];

export const supportTicketsData = [
  {
    id: 1,
    avatar: user1Image,
    name: 'Sim',
    date: '30 mins ago',
    text:
      'Lorem ipsum dolor sit amet,consectetuer edipiscing elit,sed diam nonummy nibh euismod tinciduntut laoreet doloremagna aliquam erat volutpat.',
    status: 'pending',
  },
  {
    id: 2,
    avatar: user2Image,
    name: 'Jane',
    date: '1 hour ago',
    text:
      'Lorem ipsum dolor sit amet,consectetuer edipiscing elit,sed diam nonummy nibh euismod tinciduntut laoreet doloremagna aliquam erat volutpat.',
    status: 'open',
  },
  {
    id: 3,
    avatar: user3Image,
    name: 'Tom',
    date: 'yesterday',
    text:
      'Lorem ipsum dolor sit amet,consectetuer edipiscing elit,sed diam nonummy nibh euismod tinciduntut laoreet doloremagna aliquam erat volutpat.',
    status: 'closed',
  },
];

export const todosData = [
  { id: 1, title: 'task -1', done: true },
  { id: 2, title: 'task -2', done: false },
  { id: 3, title: 'task -3', done: true },
  { id: 4, title: 'task -4', done: true },
  { id: 5, title: 'task -5', done: false },
];

export const chartjs = {
  
  bar: {
    data: {
      labels: [],
      datasets: [
        {
          label: 'Price',
          backgroundColor: '#6a82fb',
          data: [],
        }
      ],

    },
  },
  doughnut: {
    data: {
      datasets: [
        {
          data: [20, 30, 40, 50, 60],
          backgroundColor: [
            '#6a82fb',
            '#fc5c7d',
            '#45b649',
            '#00c9ff',
            '#ffd700',
          ],
          label: 'Dataset 1',
        },
      ],
      labels: ['Red', 'Orange', 'Yellow', 'Green', 'Blue'],
    },
    options: {
      responsive: true,
      legend: {
        display: false,
      },
      title: {
        display: false,
        text: 'Chart.js Doughnut Chart',
      },
      animation: {
        animateScale: true,
        animateRotate: true,
      },
    },
  },
  line: {
    data: {
      labels: [],
      datasets: [
        {
          label: 'Revenue for this year',
          borderColor: '#6a82fb',
          backgroundColor: '#6a82fb',
          data: [],
        }
      ],
    },
    options: {
      responsive: true,
      legend: {
        display: false,
      },
      title: {
        display: false,
        text: 'Chart.js Line Chart - Stacked Area',
      },
      tooltips: {
        intersect: false,
        mode: 'nearest',
      },
      hover: {
        mode: 'index',
      },
      scales: {
        xAxes: [
          {
            scaleLabel: {
              display: false,
              labelString: 'Month',
            },
            gridLines: {
              display: false,
            },
          },
        ],
        yAxes: [
          {
            stacked: true,
            scaleLabel: {
              display: false,
              labelString: 'Value',
            },
            gridLines: {
              display: false,
            },
          },
        ],
      },
    },
  },
};

function parseData(data,i,j) {

  let newData = chartjs.bar.data.labels.slice() //copy the array
  newData[j] = data.cryptocurrenciesList[i].name //execute the manipulations
  chartjs.bar.data.labels = newData //set the new state

  newData = chartjs.bar.data.datasets[0].data.slice() //copy the array
  newData[j] = parseFloat(data.cryptocurrenciesList[i].price) //execute the manipulations
  chartjs.bar.data.datasets[0].data = newData //set the new state
}

export function getData(top_stock) {
  
  fetch('https://www.alphavantage.co/query?function=TIME_SERIES_MONTHLY&symbol='+top_stock+'&apikey=HWD38M52HGVY67RN').then(results => {
      return results.json();
    }).then(data => {
      console.log(top_stock)
      let info = data["Monthly Time Series"]
      
      for (let i=0;i<12;i++){
        let date = Object.keys(info)[i]
        chartjs.line.data.datasets[0].data[i] = parseFloat(info[date]["4. close"])
      }
      chartjs.line.data.labels = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August','September','October','November','December']
    })

    fetch('https://financialmodelingprep.com/api/v3/cryptocurrencies').then(results => {
      return results.json();
    }).then(data => {
      parseData(data,0,0);
      parseData(data,1,1);
      parseData(data,3,2);
      parseData(data,5,3);
      parseData(data,11,4);
      
    })
}

