import React from 'react';
import PropTypes from 'utils/propTypes';
import { FaArrowUp, FaArrowDown } from 'react-icons/fa'

import { Card, CardText, CardTitle} from 'reactstrap';
import Typography from '../Typography';

const NumberWidget = ({
  title,
  subtitle,
  number,
  color,
  value,
  increasing,
  ...restProps
}) => {
  function Arrow(props) {
    const isIncreasing = props.isIncreasing;
    if (isIncreasing) {
      return <FaArrowUp />;
    }
    return <FaArrowDown />;
  }
  return (
    <Card body {...restProps}>
      <div className="d-flex justify-content-between">
        <CardText tag="div">
          <Typography className="mb-0">
            <strong>{title}</strong>
          </Typography>
          <Typography className="mb-0 text-muted small">{subtitle}</Typography>
        </CardText>
        <CardTitle className={`text-${color}`}>{number}</CardTitle>
      </div>
      <CardText tag="div" className="d-flex justify-content-between">
        <Typography tag="span" className="text-right text-muted small">
          {value}% <Arrow isIncreasing={increasing} />
        </Typography>
      </CardText>
    </Card>
  );
};

NumberWidget.propTypes = {
  title: PropTypes.string.isRequired,
  subtitle: PropTypes.string,
  number: PropTypes.oneOfType([
    PropTypes.string.isRequired,
    PropTypes.number.isRequired,
  ]),
  color: PropTypes.oneOf([
    'primary',
    'secondary',
    'success',
    'info',
    'warning',
    'danger',
    'light',
    'dark',
  ])
};

NumberWidget.defaultProps = {
  title: '',
  subtitle: '',
  number: 0,
  color: 'primary',
  value: 0,
  increasing: false
};

export default NumberWidget;
