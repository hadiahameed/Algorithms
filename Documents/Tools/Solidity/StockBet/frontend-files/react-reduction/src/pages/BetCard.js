import React from 'react';
import {
    CardBody
  } from 'reactstrap';

const Betcard = (props) => {
    return (
        <CardBody>
        <div className="betList">
            <p style={{'paddingTop':'1em'}}><strong>Bet ID:</strong> {props.compId}</p>
            <p style={{'paddingTop':'1em'}}><strong>Player 1 bets on :</strong> {props.team1}</p>
            <p style={{'paddingTop':'1em'}}><strong>Player 2 bets on:</strong> {props.team2}</p>
            <p style={{'paddingTop':'1em'}}><strong>Start Date:</strong> {props.sdate}</p>
            {props.bet}
        </div>
        </CardBody>
    )
};

export default Betcard;