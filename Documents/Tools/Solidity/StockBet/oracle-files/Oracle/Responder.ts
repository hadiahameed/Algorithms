const request = require('request');

function requestPromise(url:string, method:string = "GET", headers:number = -1, data:number = -1) {
    var trans:any = {
        method: method,
        url: url,
    };
    if (headers != -1)
    trans.headers = headers;
    if (data != -1) {
        trans.data = data;
        trans.json = true;
    }
    return new Promise((resolve, reject) => {
        request(trans, (err:any, response:any, data:any) => {
            if (err) {
                reject(err);
                return;
            }
            resolve(data);
        });
    });
}
function calculate_perc(body:any,start_data:string) {
    let json_obj = JSON.parse(body);
    json_obj = json_obj["Time Series (Daily)"];
    const new_price = json_obj[Object.keys(json_obj)[0]]["4. close"];
    if(json_obj[start_data]) {
        const old_price = json_obj[start_data]["4. close"];
        const perc = 100*((new_price - old_price)/parseFloat(old_price));
        return perc;
    }
    else {
        return 0
    }
    
}

export async function getResponse(query:string, params:string[]){
    let response:string[] = [];
    try{
        var stockURL_1:string = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol="+params[0].toUpperCase()+"&apikey=HWD38M52HGVY67RN";
        var stockURL_2:string = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol="+params[1].toUpperCase()+"&apikey=HWD38M52HGVY67RN";
        // Generate the URL to fetch the JSON from alphadvantage website
        let body:any = await requestPromise(stockURL_1);
        let perc = []
        perc[0] = calculate_perc(body,params[2]);
        
        if (perc[0] != 0) {
            body = await requestPromise(stockURL_2);
            if (perc[1] != 0) {
                perc[1] = calculate_perc(body,params[2]);
                let winner = 0;
                let loser = 0;
                if (perc[0] > perc[1]) {
                    winner = 1
                    loser = 1
                    console.log("Player "+winner+" wins as stock of "+params[0]+" increased by "+perc[0].toFixed(2)+"%");
                    response.push(params[0]);
                    response.push(""+perc[0].toFixed(2)+"%");
                }
                else if (perc[1] > perc[0]) {
                    winner = 2
                    loser = 0
                    console.log("Player "+winner+" wins as stock of "+params[1]+" increased by "+perc[1].toFixed(2)+"%");
                    response.push(params[1]);
                    response.push(""+perc[1].toFixed(2)+"%");

                }
            
            else {
                console.log("It's a tie!")
                response.push("NULL");
                response.push("NULL");
                response.push(params[3]);
                response.push("It's a tie!");
                return response;
            }

            response.push(params[3]);
            response.push("Player "+winner+" wins as stock of "+response[0]+" increased by "+response[1]+" as compared to stock of "+params[loser]+" which increased by only "+perc[loser].toFixed(2)+"% between today and "+params[2])
            return response;
        }
        else {
            response.push("NULL")
            response.push("NULL")
            response.push(params[3])
            response.push("Stock value not recorded on params[2]")
            return response;
        }
        }
        else {
            response.push("NULL")
            response.push("NULL")
            response.push(params[3])
            response.push("Stock value not recorded on "+ params[2])
            return response;
        }
    }
    catch(error){
        // If an error is encountered, returns an error message
        return [error,": Unable to Access data. Try again later"]
    }

}
