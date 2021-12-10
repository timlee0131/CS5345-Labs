import React, {useState} from 'react'
import Button from 'react-bootstrap/Button'
import Modal from 'react-bootstrap/Modal'

function BubbleModal() {
    const [show, setShow] = useState(false);
  
    const handleClose = () => setShow(false);
    const handleShow = () => setShow(true);
  
    return (
      <>
        <Button variant="outline-success" size="lg" onClick={handleShow}>
          View Details
        </Button>
  
        <Modal show={show} onHide={handleClose} size="lg" centered>
          <Modal.Header closeButton>
            <Modal.Title>Bubble Sort</Modal.Title>
          </Modal.Header>
          <Modal.Body>
            Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted. <br />
            Best Case Time Complexity: O(n). Best case occurs when array is already sorted. <br />
            Auxiliary Space: O(1) <br />
            Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted. <br />
            Sorting In Place: Yes <br />
            Stable: Yes <br />
            Due to its simplicity, bubble sort is often used to introduce the concept of a sorting algorithm. 
            In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines (Source: Wikipedia)
          </Modal.Body>
          <Modal.Footer>
            <Button variant="success" onClick={handleClose}>
              Close
            </Button>
          </Modal.Footer>
        </Modal>
      </>
    );
  }
  
 export default BubbleModal