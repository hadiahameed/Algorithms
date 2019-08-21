pragma solidity ^0.5.0;

// Zap contracts's methods that subscriber can call knowing the addresses
contract ZapBridge{
    function getContract(string memory contractName) public view returns (address); //coordinator
    function bond(address provider ,bytes32 endpoint, uint256 dots) public;
    function unbond(address provider ,bytes32 endpoint, uint256 dots) public;
    function calcZapForDots(address provider, bytes32 endpoint, uint256 dots) external view returns (uint256); //bondage
    function delegateBond(address holderAddress, address oracleAddress, bytes32 endpoint, uint256 numDots) external returns (uint256 boundZap); //bondage
    function query(address provider, string calldata queryString, bytes32 endpoint, bytes32[] calldata params) external returns (uint256); //dispatch
    function approve(address bondage, uint256 amount) public returns (bool); // Zap Token
}

contract Subscriber {

    address public owner;
    ZapBridge public coordinator;
    address provider;
    bytes32 endpoint;
    uint256 query_id;
    string[] public response;

    event ReceiveResponse(uint256 indexed id, string result);
    event Bonded();


    //Coordinator contract is one single contract that
    //knows all other Zap contract addresses
    constructor(address _coordinator, address _provider, bytes32 _endpoint) public{
        owner = msg.sender;
        coordinator = ZapBridge(_coordinator);
        provider = _provider;
        endpoint = _endpoint;
    }

    //This function call can be skipped if owner approve and delegateBond for this contract
    function approve(uint256 amount) public returns (bool){
      address ZapTokenAddress = coordinator.getContract("ZAP_TOKEN");
      address BondageAddress = coordinator.getContract("BONDAGE");
      return ZapBridge(ZapTokenAddress).approve(BondageAddress,amount);

    }

    //This function call can be ommitted if owner call delegateBond directly to Bondage contract
    //Contract has to hold enough zap approved
    function bond(uint256 dots) public{
        address BondageAddress = coordinator.getContract("BONDAGE");
        ZapBridge(BondageAddress).bond(provider,endpoint,dots);
        emit Bonded();
    }

    //This function call can be ommitted if owner call delegateBond directly to Bondage
    function unbond(uint256 dots) public{
        address BondageAddress = coordinator.getContract("BONDAGE");
        return ZapBridge(BondageAddress).bond(provider,endpoint,dots);
    }

    //Query offchain or onchain provider.
    function query(string memory queryString, bytes32[] memory params) public returns (uint256) {
        address dispatchAddress = coordinator.getContract("DISPATCH");
        query_id = ZapBridge(dispatchAddress).query(provider,queryString,endpoint,params);
        return query_id;
    }
    function append(string memory a, string memory b, string memory c, string memory d) internal pure returns (string memory) {
        return string(abi.encodePacked(a,',',b,',', c,',',d));
    }

    //Implementing callback that will accept provider's respondIntArray
    //Response method options  are  :respondBytes32Array, respondIntArray, respond1, respond2, respond3, respond4
    function callback(uint256 _id, string calldata _response) external{
        response.length = 0;
        require(_id==query_id,"Wrong query Id");
        response.push(_response);
        emit ReceiveResponse(_id, _response);
        //Implement your logic with _response data here
    }
    function callback(uint256 _id, string calldata _response1, string calldata _response2) external{
        response.length = 0;
        require(_id==query_id,"Wrong query Id");
        response.push(_response1);
        response.push(_response2);
        emit ReceiveResponse(_id, append(_response1,_response2,'',''));
        //Implement your logic with _response data here
    }
    function callback(uint256 _id, string calldata _response1,string calldata _response2,string calldata _response3 ) external{
        response.length = 0;
        require(_id==query_id,"Wrong query Id");

        response.push(_response1);
        response.push(_response2);
        response.push(_response3);
        emit ReceiveResponse(_id, append(_response1,_response2,_response3,''));
        //Implement your logic with _response data here
    }

    function callback(uint256 _id, string calldata _response1,string calldata _response2,string calldata _response3,string calldata _response4 ) external{
        response.length = 0;
        require(_id==query_id,"Wrong query Id");

        response.push(_response1);
        response.push(_response2);
        response.push(_response3);
        emit ReceiveResponse(_id, append(_response1,_response2,_response3,_response4));
        //Implement your logic with _response data here
    }

}
