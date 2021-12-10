import React, {useState} from 'react'
import Button from 'react-bootstrap/Button'
import Modal from 'react-bootstrap/Modal'

function InsertionModal() {
    const [show, setShow] = useState(false);
  
    const handleClose = () => setShow(false);
    const handleShow = () => setShow(true);
  
    return (
      <>
        <Button variant="outline-danger" size="lg" onClick={handleShow}>
          View Details
        </Button>
  
        <Modal show={show} onHide={handleClose} size="lg" centered>
          <Modal.Header closeButton>
            <Modal.Title>Insertion Sort</Modal.Title>
          </Modal.Header>
          <Modal.Body>
            Time Complexity: O(n^2) <br />
            Auxiliary Space: O(1) <br />
            Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted. <br />
            Algorithmic Paradigm: Incremental Approach <br />
            Sorting In Place: Yes <br />
            Stable: Yes <br />

            Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
          </Modal.Body>
          <Modal.Footer>
            <Button variant="danger" onClick={handleClose}>
              Close
            </Button>
          </Modal.Footer>
        </Modal>
      </>
    );
  }
  
 export default InsertionModal