import React from 'react';

import BubbleModal from './BubbleModal'
import MergeModal from './MergeModal'
import InsertionModal from './InsertionModal'

import CardGroup from 'react-bootstrap/CardGroup'
import Card from 'react-bootstrap/Card'

import green from '../images/green.png'
import blue from '../images/blue.png'
import red from '../images/red.jpeg'

function SortingCards() {
    return (
        <CardGroup>
            <Card>
                <Card.Img variant="top" src={green} />
                <Card.Body>
                <Card.Title>Bubble Sort</Card.Title>
                <Card.Text>
                    This is a wider card with supporting text below as a natural lead-in to
                    additional content. This content is a little bit longer.
                </Card.Text>
                </Card.Body>
                <Card.Footer>
                    <div className="d-grid gap-2">
                        <BubbleModal />
                    </div>
                </Card.Footer>
            </Card>

            <Card>
                <Card.Img variant="top" src={blue} />
                <Card.Body>
                <Card.Title>Merge Sort</Card.Title>
                <Card.Text>
                    This card has supporting text below as a natural lead-in to additional
                    content.{' '}
                </Card.Text>
                </Card.Body>
                <Card.Footer>
                    <div className="d-grid gap-2">
                        <MergeModal />
                    </div>
                </Card.Footer>
            </Card>

            <Card>
                <Card.Img variant="top" src={red} />
                <Card.Body>
                <Card.Title>Insertion Sort</Card.Title>
                <Card.Text>
                    This is a wider card with supporting text below as a natural lead-in to
                    additional content. This card has even longer content than the first to
                    show that equal height action.
                </Card.Text>
                </Card.Body>
                <Card.Footer>
                    <div className="d-grid gap-2">
                        <InsertionModal />
                    </div>
                </Card.Footer>
            </Card>
        </CardGroup>
    )
}

export default SortingCards