const subscriber = artifacts.require("Subscriber")
const COORDINATOR = "0xb007eca49763f31edff95623ed6c23c8c1924a16"
const OracleAddress = ""
const OracleEndpoint=""
module.exports = function(deployer) {
  deployer.deploy(subscriber,COORDINATOR,OracleAddress,OracleEndpoint);
};
