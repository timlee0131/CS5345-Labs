import React from 'react';
import './../App.css';

import Navbar from 'react-bootstrap/Navbar'
import Nav from 'react-bootstrap/Nav'
import Button from 'react-bootstrap/Button'
// import NavDropdown from 'react-bootstrap/NavDropdown'
import Container from 'react-bootstrap/Container'

import icon from '../images/favicon.ico'

function NavComponent(props) {
    return (
        <Navbar bg="dark" expand="lg" variant="dark">
            <Container>
                <img
                    alt=""
                    src={icon}
                    width="30"
                    height="30"
                    className="d-inline-block align-top"
                /> {'\t'}
                <Navbar.Brand href="#home">Sorting Engine</Navbar.Brand>
                <Navbar.Toggle aria-controls="basic-navbar-nav" />
                <Navbar.Collapse id="basic-navbar-nav">
                <Nav className="me-auto">
                </Nav>
                <div>
                <a href="/CS5345Final/Emscripten/frontend/sort.html" target="_blank"><Button variant="warning" size="sm" active>Demo Web App</Button></a>{' '}
                    <a href="code.zip" download><Button variant="warning" size="sm" active>Download Native App</Button></a>
                </div>
                </Navbar.Collapse>
            </Container>
        </Navbar>
    )
}

export default NavComponent