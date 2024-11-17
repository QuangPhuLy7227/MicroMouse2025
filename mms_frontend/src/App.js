import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Navbar from './component/navbar';
import Simulator from './page/simulator';
import Periscope from './page/periscope';
import ControlPanel from './page/controlPanel';
import Test from './page/testConnection';
import ColorDialogTest from './page/testColor';


function App() {
  return (
    <Router>
      <Navbar />  

      <Routes>
        <Route path="/" element={<Simulator />} />  
        <Route path="/periscope" element={<Periscope />} />
        <Route path="/control-panel" element={<ControlPanel />} />
        <Route path="/test" element={<Test />} />
        <Route path="/color" element={<ColorDialogTest />} />
      </Routes>
    </Router>
  );
}

export default App;
