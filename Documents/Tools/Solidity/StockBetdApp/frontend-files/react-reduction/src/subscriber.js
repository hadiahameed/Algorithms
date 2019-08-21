import web3 from './web3';

const address = '0xd1b85d9393af8802543b0b2553ba383a9d2b115c'; // deployed contract, did some console.log, copypastaed from terminal
const abi =[
	{
		"constant": false,
		"inputs": [
			{
				"name": "amount",
				"type": "uint256"
			}
		],
		"name": "approve",
		"outputs": [
			{
				"name": "",
				"type": "bool"
			}
		],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "dots",
				"type": "uint256"
			}
		],
		"name": "bond",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "_id",
				"type": "uint256"
			},
			{
				"name": "_response1",
				"type": "string"
			},
			{
				"name": "_response2",
				"type": "string"
			},
			{
				"name": "_response3",
				"type": "string"
			},
			{
				"name": "_response4",
				"type": "string"
			}
		],
		"name": "callback",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "_id",
				"type": "uint256"
			},
			{
				"name": "_response",
				"type": "string"
			}
		],
		"name": "callback",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "_id",
				"type": "uint256"
			},
			{
				"name": "_response1",
				"type": "string"
			},
			{
				"name": "_response2",
				"type": "string"
			},
			{
				"name": "_response3",
				"type": "string"
			}
		],
		"name": "callback",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "_id",
				"type": "uint256"
			},
			{
				"name": "_response1",
				"type": "string"
			},
			{
				"name": "_response2",
				"type": "string"
			}
		],
		"name": "callback",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "queryString",
				"type": "string"
			},
			{
				"name": "params",
				"type": "bytes32[]"
			}
		],
		"name": "query",
		"outputs": [
			{
				"name": "",
				"type": "uint256"
			}
		],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": false,
		"inputs": [
			{
				"name": "dots",
				"type": "uint256"
			}
		],
		"name": "unbond",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"inputs": [
			{
				"name": "_coordinator",
				"type": "address"
			},
			{
				"name": "_provider",
				"type": "address"
			},
			{
				"name": "_endpoint",
				"type": "bytes32"
			}
		],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "constructor"
	},
	{
		"anonymous": false,
		"inputs": [
			{
				"indexed": true,
				"name": "id",
				"type": "uint256"
			},
			{
				"indexed": false,
				"name": "result",
				"type": "string"
			}
		],
		"name": "ReceiveResponse",
		"type": "event"
	},
	{
		"constant": true,
		"inputs": [],
		"name": "coordinator",
		"outputs": [
			{
				"name": "",
				"type": "address"
			}
		],
		"payable": false,
		"stateMutability": "view",
		"type": "function"
	},
	{
		"constant": true,
		"inputs": [],
		"name": "owner",
		"outputs": [
			{
				"name": "",
				"type": "address"
			}
		],
		"payable": false,
		"stateMutability": "view",
		"type": "function"
	},
	{
		"constant": true,
		"inputs": [
			{
				"name": "",
				"type": "uint256"
			}
		],
		"name": "response",
		"outputs": [
			{
				"name": "",
				"type": "string"
			}
		],
		"payable": false,
		"stateMutability": "view",
		"type": "function"
	}
]
// local abstraction of contract
export default new web3.eth.Contract(abi, address);

