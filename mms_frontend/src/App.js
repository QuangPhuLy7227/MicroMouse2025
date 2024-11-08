import React, { useState, useEffect, useCallback } from 'react';
import axios from 'axios';

function App() {
  const API_BASE_URL = process.env.REACT_APP_API_URL;
  const [count, setCount] = useState(0);

  // Memoize the fetchCount function
  const fetchCount = useCallback(async () => {
    try {
      const response = await axios.get(`${API_BASE_URL}/count`);
      setCount(response.data.count);
    } catch (error) {
      console.error('Error fetching count:', error);
    }
  }, [API_BASE_URL]);

  useEffect(() => {
    fetchCount();
  }, [fetchCount]);

  const incrementCount = async () => {
    try {
      const response = await axios.post(`${API_BASE_URL}/increment`);
      setCount(response.data.count);
    } catch (error) {
      console.error('Error incrementing count:', error);
    }
  };

  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      <h1>Welcome to the page</h1>
      <button onClick={incrementCount}>Press me</button>
      <p>You have pressed the button {count} times.</p>
    </div>
  );
}

export default App;
