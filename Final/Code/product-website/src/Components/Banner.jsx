import Card from 'react-bootstrap/Card'
import Container from 'react-bootstrap/Container'
import Row from 'react-bootstrap/Row'
import Col from 'react-bootstrap/Col'

import logo from '../images/logo2.jpeg'

function Banner() {
    return (
        <Card className="bg-dark text-black">
        <Card.Img src={logo} alt="image" />
        <Card.ImgOverlay>
            <br />
            <br />
            <Container fluid="md">
                <Row>
                    <Col xs={6}>
                        <blockquote class="blockquote text-center" fluid>
                            <p class="mb-0">
                            In computing, sorting is the process of rearranging an initially unordered sequence of records until they are ordered with respect to all of or that part of each record designated as its key.
                            </p>
                            <br />
                            <footer class="blockquote-footer">Edwin D. Reilly  <cite title="Source Title">Encyclopedia of Computer Science</cite></footer>
                        </blockquote>
                    </Col>
                    <Col xs={12}></Col>
                    {/* <Col></Col> */}
                </Row>
            </Container>
        </Card.ImgOverlay>
        </Card>
    )
}

export default Banner