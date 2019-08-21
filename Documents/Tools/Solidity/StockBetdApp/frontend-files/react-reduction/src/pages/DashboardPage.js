//import update from 'react-addons-update'; // ES6
import web3 from '../web3';
import Betcard from './BetCard'
import {
    Form,
    FormGroup,
    Input,
    Label
  } from 'reactstrap';

import subscriber from '../subscriber';
import { AnnouncementCard, TodosCard } from 'components/Card';
//import HorizontalAvatarList from 'components/HorizontalAvatarList';
//import MapWithBubbles from 'components/MapWithBubbles';
import Page from 'components/Page';
//import ProductMedia from 'components/ProductMedia';
//import SupportTicket from 'components/SupportTicket';
//import UserProgressTable from 'components/UserProgressTable';
import { IconWidget, NumberWidget } from 'components/Widget';
//import { getStackLineChart, stackLineChartOptions } from 'demos/chartjs';
import {
  avatarsData,
  chartjs,
  productsData,
  supportTicketsData,
  todosData,
  userProgressTableData,
  getData
} from 'demos/dashboardPage';
import React from 'react';
//import { Bar, Line } from 'react-chartjs-2';
import ClipLoader from 'react-spinners/ClipLoader';
import {
  MdBubbleChart,
  MdInsertChart,
  MdPersonPin,
  MdPieChart,
  MdRateReview,
  MdShare,
  MdShowChart,
  MdThumbUp,
} from 'react-icons/md';
import InfiniteCalendar from 'react-infinite-calendar';
import {
  Badge,
  Button,
  Card,
  CardBody,
  CardDeck,
  CardGroup,
  CardHeader,
  CardTitle,
  Col,
  ListGroup,
  ListGroupItem,
  Row,
} from 'reactstrap';
import { getColor } from 'utils/colors';

const today = new Date();
const lastWeek = new Date(
  today.getFullYear(),
  today.getMonth(),
  today.getDate() - 7,
  );

  class DashboardPage extends React.Component {
    constructor() {
      super();
      this.handleSubmit = this.handleSubmit.bind(this);
      this.state = {
        top_stock: '',
        stockprice: [''],
        stockname: [''],
        percInc: [0],
        increasing: [false],
        loaded: false,
        dots: 1,
        names: [''],
        response: [''],
        bondingFlag: '',
        queringFlag: '',
        team1: 'AAPL',
        team2: 'FB',
        sdate: '2019-07-10',
        compId: '',
        bet: '',
        betList:[],
        results:[''],
        disabledButton: false,
        ids:[]

      };
    }

      randomSerial() {
        var chars = '1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
        var serialLength = 10
        var randomSerial = ""
        var i
        var randomNumber

        for (i = 0; i < serialLength; i = i + 1) {
            randomNumber = Math.floor(Math.random() * chars.length);
            randomSerial += chars.substring(randomNumber, randomNumber + 1);
        }
        return randomSerial
      }
      updateTeam1(evt) {
        this.setState({team1: evt.target.value})
      }
      updateTeam2(evt) {
        this.setState({team2: evt.target.value})
      }
      updateSDate(evt) {
        this.setState({sdate: evt.target.value})
      }
      updateCompId(evt) {
        this.setState({compId: evt.target.value})
      }

      handleSubmit = async event => {
        event.preventDefault();
        let ID = this.randomSerial()
        this.setState({disabledButton: true})
        this.setState({compId: ID})
        this.setState({bet:<Button disabled={this.state.disabledButton} onClick={this.bond}>Bet</Button>})
        let arr = this.state.betList
        arr.push(<Betcard key={this.randomSerial()} compId = {ID} team1 = {this.state.team1} team2 = {this.state.team2} sdate = {this.state.sdate} bet = {<Button disabled={this.state.disabledButton} onClick={this.bond}>Bet</Button>}/>)
        console.log(arr)
        this.setState({betList:arr}, () => {console.log(this.state.betList)})

      }
    parseData(data,i) {

      let newData = this.state.stockprice.slice() //copy the array
      newData[i] = "$"+data.mostGainerStock[i].price //execute the manipulations
      this.setState({stockprice: newData}) //set the new state

      newData = this.state.stockname.slice() //copy the array
      newData[i] = data.mostGainerStock[i].companyName //execute the manipulations
      this.setState({stockname: newData}) //set the new state

      let percCh = data.mostGainerStock[i].changesPercentage
      percCh = percCh.replace(/['()]+/g, '')
      percCh = parseFloat(percCh)
      let increasing = true
      if(percCh < 0) increasing =  false

      newData = this.state.increasing.slice() //copy the array
      newData[i] = increasing //execute the manipulations
      this.setState({increasing: newData}) //set the new state

      newData = this.state.percInc.slice() //copy the array
      newData[i] = percCh //execute the manipulations
      this.setState({percInc: newData}) //set the new state
    }

    bond = async (event) => {
      event.preventDefault();
      this.setState({disabledButton: true})
      
      const accounts = await web3.eth.getAccounts();
      this.setState({bondingFlag: <h6>Bonding...<ClipLoader /> </h6>})
      await subscriber.methods.bond(this.state.dots).send({
        from: accounts[0],
      });

      const bytes32Arr = [];
        bytes32Arr.push(web3.utils.fromAscii(this.state.team1));
        bytes32Arr.push(web3.utils.fromAscii(this.state.team2));
        bytes32Arr.push(web3.utils.fromAscii(this.state.sdate));
        bytes32Arr.push(web3.utils.fromAscii(this.state.compId));
        this.setState({bondingFlag: <h6>Querying...<ClipLoader /> </h6>})
        await subscriber.methods.query("bet", bytes32Arr).send({
            from: accounts[0],
        });
    };


    query = async (event) => {
        event.preventDefault();
        this.setState({bondingFlag: <ClipLoader />})
        await this.bond
        const accounts = await web3.eth.getAccounts();
        const bytes32Arr = [];
        bytes32Arr.push(web3.utils.fromAscii(this.state.team1));
        bytes32Arr.push(web3.utils.fromAscii(this.state.team2));
        bytes32Arr.push(web3.utils.fromAscii(this.state.sdate));
        bytes32Arr.push(web3.utils.fromAscii(this.state.compId));
        await subscriber.methods.query("bet", bytes32Arr).send({
            from: accounts[0],
        });

      };


    componentDidMount() {

      subscriber.events.ReceiveResponse()
      .on('data', (event) => {
        let value = event.returnValues.result;
        let resArray = value.split(',');
        resArray.forEach((res,index) =>  {
          if (res !== '') {
            resArray[index] = res;
          }
        });
        this.setState({bondingFlag: ''})
        this.setState({response: resArray});
        this.setState({queryingFlag: resArray[3]});
        let arr = this.state.results
        arr.push(<div style={{'float':'right'}}className="col-18">{this.state.queryingFlag}</div>)
        this.setState({results:arr})
        arr = this.state.betList
        let betIds = this.state.ids
        
        betIds.push(resArray[2])
        this.setState({ids: betIds})
        arr[arr.length-1] = <div style={{'float':'right'}}className="col-18"><strong>Bet ID: {betIds[betIds.length - 1]}:</strong> {this.state.queryingFlag}</div>
        this.setState({betList:arr})
        this.setState({disabledButton: false})
      }).on('error', console.error);

      fetch('https://financialmodelingprep.com/api/v3/stock/gainers').then(results => {
      return results.json();
    }).then(data => {
      this.parseData(data,0);
      this.setState({top_stock: data.mostGainerStock[0].ticker})
      this.parseData(data,1);
      this.parseData(data,2);
      this.parseData(data,3);
      return this.state.top_stock;

    }).then( (top_stock) => {
      getData(top_stock);
    }).then(() => {
      this.setState({loaded:true})
    })

    // this is needed, because InfiniteCalendar forces window scroll
    window.scrollTo(0, 0);
  }

  render() {
    let items = []
    let res = this.state.betList
    if (res.length!==0) {
      for (const value of res) {
        items.push(value)
      }
    }

    return (
      <Page
className="DashboardPage"
title="Create a Bet"
>
<Row>
    <Col lg={3} md={6} sm={6} xs={12}>
        <NumberWidget
        title= {this.state.stockname[0]}
        subtitle="Highest stock"
        number= {this.state.stockprice[0]}
        color="secondary"
        value={this.state.percInc[0]}
        increasing={this.state.increasing[0]}
        />
    </Col>

    <Col lg={3} md={6} sm={6} xs={12}>
        <NumberWidget
        title= {this.state.stockname[1]}
        subtitle="Second Highest stock"
        number= {this.state.stockprice[1]}
        color="secondary"
        value={this.state.percInc[1]}
        increasing={this.state.increasing[1]}
        />
    </Col>

    <Col lg={3} md={6} sm={6} xs={12}>
        <NumberWidget
        title= {this.state.stockname[2]}
        subtitle="Third Highest stock"
        number= {this.state.stockprice[2]}
        color="secondary"
        value={this.state.percInc[2]}
        increasing={this.state.increasing[2]}
        />
    </Col>

    <Col lg={3} md={6} sm={6} xs={12}>
        <NumberWidget
        title= {this.state.stockname[3]}
        subtitle="Fourth Highest stock"
        number= {this.state.stockprice[3]}
        color="secondary"
        value={this.state.percInc[3]}
        increasing={this.state.increasing[3]}
        />
    </Col>
</Row>

<Row>
    <Col lg="8" md="12" sm="12" xs="12">
        <Card>
            <CardHeader>
                Bet on Stocks
            </CardHeader>
            <CardBody>
                {/*<form  onSubmit={this.bond}>
                    <h4>Bond to the Oracle</h4>
                    <div className="form-group">
                        <label className="col-sm-10">Amount of dots to bond: </label>
                        <div className="col-sm-10">
                            <input
                            className="form-control"
                            type = "number"
                            size="4"
                            value = {this.state.dots}
                            onChange={event => this.setState({ dots: event.target.value })}
                            />
                        </div>

                    </div>
                    <div className="form-group">
                        <div className="row">
                            <div className="col-2">
                                <button id="bonddots" type="submit" className="btn btn-primary">Bond</button>
                            </div>
                            <div className="col-8">
                                {this.state.bondingFlag}
                            </div>
                        </div>
                    </div>
                </form>*/}

      <Row>
        <Col xl={6} lg={12} md={12}>
          <Card>
            <CardHeader>Create a bet</CardHeader>
            <CardBody>
              <Form onSubmit={this.handleSubmit}>
                <FormGroup>
                <Label for="teamA">Stock 1</Label>
                  <Input id= "teamA" className="mb-2" name = "team1" placeholder="sm" bsSize="sm" placeholder="AAPL" onChange={event => {this.updateTeam1(event)}}/>
                </FormGroup>
                <FormGroup>
                <Label for="teamB">Stock 2</Label>
                  <Input id= "teamB" className="mb-2" name = "team2" placeholder="sm" bsSize="sm" placeholder="FB" onChange={event => {this.updateTeam2(event)}}/>
                </FormGroup>
                <FormGroup>
                  <Label for="startDate">Start Date</Label>
                  <Input
                    type="date"
                    name="date"
                    id="satrtDate"
                    placeholder="2019-07-30"
                    onChange={event => {this.updateSDate(event)}}
                  />
                </FormGroup>
                <Button disabled={this.state.disabledButton}>Submit</Button><div style={{'float':'right'}}className="col-18">{this.state.bondingFlag}</div>
              </Form>
            </CardBody>
          </Card>
        </Col>
        <Col xl={6} lg={12} md={12}>
           <Card>
            <CardHeader>List of bets</CardHeader>
            {items}
          </Card>
        </Col>
              </Row>


            </CardBody>
            {/*<CardBody>
                <form onSubmit={this.query}>

                    <h4>Compare Stock Prices</h4>
                    <div className="form-group">
                        <label className="col-sm-2 control-label">Stock 1</label>
                        <div className="col-sm-10">
                          <input
                            className="form-control"
                            value = {this.state.team1}
                            onChange ={ event  => {
                                this.setState({team1: event.target.value}) //set the new state
                            }}
                            />
                        </div>
                    </div>
                    <div className="form-group">
                        <label className="col-sm-2 control-label">Stock 2</label>
                        <div className="col-sm-10">
                            <input
                            className="form-control"
                            value = {this.state.team2}
                            onChange ={ event  => {
                                this.setState({team2: event.target.value}) //set the new state
                            }}
                            />
                        </div>
                    </div>
                    <div className="form-group">
                        <label className="col-sm-2 control-label">Start Date</label>
                        <div className="col-sm-10">
                            <input
                            className="form-control"
                            value = {this.state.sdate}
                            onChange ={ event  => {
                                this.setState({sdate: event.target.value}) //set the new state
                            }}
                            />
                        </div>
                    </div>
                    <div className="form-group">
                            <div className="col-2">
                              <button id="queryoracle" type="submit" className="btn btn-primary">Query</button>
                            </div>
                        <div className="col-8">
                          {this.state.queryingFlag}
                        </div>
                    </div>
                </form>
            </CardBody>*/}
            <CardBody>
                    <h4>Winner</h4>
                    <div className="form-group">
                        <div className="col-sm-10">
                          Name: {this.state.response[0]}
                        </div>
                        <div className="col-sm-10">
                          Percentage: {this.state.response[1]}
                        </div>
                    </div>
            </CardBody>
        </Card>
    </Col>

</Row>
</Page>


          );
        }
      }
      export default DashboardPage;
