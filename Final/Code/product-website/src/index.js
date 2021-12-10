import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';

import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row'
import Col from 'react-bootstrap/Col'
// import Image from 'react-bootstrap/Image'

// import logo from './images/logo2.jpeg'

import 'bootstrap';
import 'bootstrap/dist/css/bootstrap.min.css';

import Navbar from './Components/NavComponent';
import Banner from './Components/Banner'

ReactDOM.render(
  <React.StrictMode>
    <Navbar/>
    {/* <Image src={logo} width="100%" /> */}
    <Banner />
    <Container>
      <Row>
        <Col></Col>
        <Col xs={16}>
          <App /> 
        </Col>
        <Col></Col>
      </Row>
    </Container>
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
