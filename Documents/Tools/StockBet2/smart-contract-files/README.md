# ZAP Onchain Subscriber


This repository provides template for onchain subscriber to set Oracle address and endpoint to use,
bond/unbond , query, and process response, all onchain

## Getting Started

- `yarn`
- `./node_modules/.bin/truffle compile`
- Edit `migrations/2_subscriber_migration.js` to specify provider and endpoint information
- `./node_modules/.bin/truffle migrade -f 2 --to 2 --network main`
* Kovan network available with different Coordinator address
