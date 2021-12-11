import React from 'react'

import Container from 'react-bootstrap/Container'
import Image from 'react-bootstrap/Image'

function FooterSection() {
    return (
        <div>
            <hr />
            <Container>
                <h5 style={{textAlign: "center"}}>Final Project for CS5345</h5>
                <h6 style={{textAlign: "center"}}>Created by Timothy Lee</h6>
                <Image className="mx-auto d-block" src="smulyle.png" alt="" fluid />
            </Container>
            <br />
        </div>
    )
}

export default FooterSection