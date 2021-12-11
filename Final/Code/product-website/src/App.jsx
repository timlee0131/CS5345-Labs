import './App.css';

import SortingCards from './Components/SortingCards'
import Overview from './Components/Overview'

function App() {
  return (
    <div className="App">
      <br />
      <br />

      <Overview />
      <br />
      <br />

      <h3 class="display-6">Brief Overview of Sorting Algorithms Used in this App</h3>
      <SortingCards />
    </div>
  )
}

export default App;
