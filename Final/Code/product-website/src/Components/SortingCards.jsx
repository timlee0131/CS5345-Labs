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
                    Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
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
                    Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
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
                    The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
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