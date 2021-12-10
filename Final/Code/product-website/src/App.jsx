
import Table from 'react-bootstrap/Table'
// import Image from 'react-bootstrap/Image'

import './App.css';
// import logo from './images/logo2.jpeg'

import SortingCards from './Components/SortingCards'

function App() {
  return (
    <div className="App">
      {/* <h1 className="display-3">Welcome to the Sorting Engine</h1> */}
      {/* <Image src={logo} fluid /> */}

      <br />
      <br />

      {/* <blockquote class="blockquote text-center">
        <p class="mb-0">
          In computing, sorting is the process of rearranging an initially unordered sequence of records until they are ordered with respect to all of or that part of each record designated as its key.
        </p>
        <br />
        <footer class="blockquote-footer">Edwin D. Reilly  <cite title="Source Title">Encyclopedia of Computer Science</cite></footer>
      </blockquote> */}

      <br />

      <h3>Brief Overview of Sorting Algorithms Used in this App</h3>
      <SortingCards />

      <br />
      <br />
      <Table responsive>
        <thead>
          <tr>
            <th>#</th>
            {Array.from({ length: 12 }).map((_, index) => (
              <th key={index}>Table heading</th>
            ))}
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>1</td>
            {Array.from({ length: 12 }).map((_, index) => (
              <td key={index}>Table cell {index}</td>
            ))}
          </tr>
          <tr>
            <td>2</td>
            {Array.from({ length: 12 }).map((_, index) => (
              <td key={index}>Table cell {index}</td>
            ))}
          </tr>
          <tr>
            <td>3</td>
            {Array.from({ length: 12 }).map((_, index) => (
              <td key={index}>Table cell {index}</td>
            ))}
          </tr>
          <tr>
            <td>3</td>
            {Array.from({ length: 12 }).map((_, index) => (
              <td key={index}>Table cell {index}</td>
            ))}
          </tr>
          <tr>
            <td>3</td>
            {Array.from({ length: 12 }).map((_, index) => (
              <td key={index}>Table cell {index}</td>
            ))}
          </tr>
          <tr>
            <td>3</td>
            {Array.from({ length: 12 }).map((_, index) => (
              <td key={index}>Table cell {index}</td>
            ))}
          </tr>
        </tbody>
      </Table>
    </div>
  )
}

export default App;
