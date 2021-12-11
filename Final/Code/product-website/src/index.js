import React from 'react';
import ReactDOM from 'react-dom';
import { BrowserRouter, Route, Routes } from 'react-router-dom'
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';

import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row'
import Col from 'react-bootstrap/Col'
import FooterSection from './Components/FooterSection';

import 'bootstrap';
import 'bootstrap/dist/css/bootstrap.min.css';

import Navbar from './Components/NavComponent';
import Banner from './Components/Banner'

// import Sort from './Emscripten/frontend/sort.html'

// const reload = () => window.location.reload();

ReactDOM.render(
  <React.StrictMode>
    <BrowserRouter>
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
    <FooterSection />
    <Routes>
      <Route path="../Emscripten/frontend/sort.html" />
    </Routes>
    </BrowserRouter>
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
