const Web3 = require("web3")
const HDWalletProviderMem = require("truffle-hdwallet-provider");
const fs = require("fs")
const wutils = require("web3-utils")
const mnemonic = "goddess delay either cheese dwarf gap grass patrol hover situate renew swarm"
let abi = fs.readFileSync("build/contracts/Subscriber.json","utf-8")
const subAddress = "0x0c76bb5056B72C0E4A4dF2f269F3265719e67bF5"
const provider = "0xA4E5cD0B3d4A050734d2Fe310B30AB0a80e72eAe"
const ZapToken = require("@zapjs/zaptoken").ZapToken
const ZapBondage = require("@zapjs/bondage").ZapBondage
const endpoint = "PoloniexAPI"
async function setup(){
  const web3 = new Web3(new HDWalletProviderMem(mnemonic,"https://forcibly-gorgeous-lioness.quiknode.io/d72af252-8437-46b3-85f9-91a7b46e0ead/E-9zBWkdoIS18bH3CXEhLA==/"))

  const accounts = await web3.eth.getAccounts()
  let subscriber = accounts[0]
  console.log(accounts)
  abi = JSON.parse(abi)
  let subContract = new web3.eth.Contract(abi.abi,subAddress)
  // let tx = await subContract.methods.setProvider(provider,wutils.utf8ToHex(endpoint)).send({from:subscriber, gasPrice:4000000000})
  const zapBondage = new ZapBondage({networkProvider:web3})
  const zapToken = new ZapToken({networkProvider:web3,networkId:1})
  // let tx= await zapToken.approve({
  //           to: zapBondage.contract._address,
  //           amount: wutils.toBN(wutils.toWei("1000")),
  //           from: subscriber,
  //           gasPrice:wutils.toHex(4000000000)
  //       });
  // console.log(tx)
  // tx = await zapBondage.delegateBond({provider, endpoint, dots:2, subscriber:subAddress, from:subscriber})
  // console.log(tx)
  const boundDots = await zapBondage.getBoundDots({provider,subscriber:subAddress,endpoint})
  console.log(boundDots)
  // tx = await subContract.methods.query("queryFromPropulsor",[wutils.utf8ToHex("ETH"),wutils.utf8ToHex("BTC")]).send({from:subscriber,gasPrice:4000000000})
  // console.log(tx)
  // console.log(JSON.stringify(tx))
  tx = await subContract.methods.unbond(wutils.utf8ToHex(endpoint),wutils.toHex(1)).send({from:subscriber,gasPrice:4000000000})
  console.log(tx)
}
setup()
.then(console.log)
.catch(console.error)
