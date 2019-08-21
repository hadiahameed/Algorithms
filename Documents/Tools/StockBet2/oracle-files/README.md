# Zap-oracle-template-StockBet

## Purpose :
This oracle allows users to know the percentage increase in the stock value of two equities from a specific start date to the current date. The oracle takes four parameters: ["stock1","stock2","start_date","compId"]

An example of querying the oracle to bet on Apple's (AAPL) and Facebook's (FB) stocks:
+ **Query**: bet
+ **Param**: AAPL
+ **Param**: FB
+ **Param**: 2019-07-30
+ **Param**: compId (comes from the smart contract querying it but pass any arbitrary string if you are simply testing the oracle.)

and so on.

API used: https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=demo
(Get your free API key from alphadvantage and replace "demo" with it for apikey in the url)


## Running an oracle:
1. After cloning, run `yarn` in the project directory.
2. In the Oracle/Config.json, add your MetaMask mnemonic on line 6.
2. Run `npm run build`.
3. Run `npm run start`

## Querying an oracle as an off-chain subscriber:

+ Follow instructions for running zap-term
[zap-term]: https://github.com/hadiahameed/zap-term

## ORACLE TEMPLATE SETUP EXPLAINED

### Config Setting :
  - Oracle's information :
    + Title, Public key, Mnemonic, Node URL
    + Endpoint : Name, Curve, broker, md (description about endpoint), query list ( query string accepted and response type)
### What will be created  once setup and run:
1. Oracle registered if none exists
2. Endpoint created if Endpoint name in config has not been created
  + Endpoint.json file will be created containing information about query list and endpoint, saved in ipfs and set as Endpoint's params on-chain
  + Endpoint.md file will be created, saved in ipfs and set as Provider's params on-chain
3. If Endpoint is already initiated, the step 2 will be ignored


### Code Layout :

1. Config.ts : data about your wallet ,ethereum node and your provider's pubkey and title
3. Oracle.ts : Template for Create/Manage flow
4. Responder.ts : Stub callback function when receive query event and return result. Make changes to this function to add your own oracle's functionality to it. 

## Note :
- A query consists of the querystring 'bet' and an array of parameters.
- Choose the stock name for params[0] and params[1] from the following list e.g. AAPL to find the stock price for Apple's stocks:
https://financialmodelingprep.com/api/v3/stock/real-time-price
- Choose the start date i.e. params[2] from the following dates 
https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=demo
- Ensure you have enough ETH in your address for responding to queries
