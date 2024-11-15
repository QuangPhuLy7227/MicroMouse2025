// import React, { useState, useEffect, useCallback } from 'react';
// import axios from 'axios';

// function Test() {
//   const API_BASE_URL = process.env.REACT_APP_API_URL;
//   const [count, setCount] = useState(0);

//   // Memoize the fetchCount function
//   const fetchCount = useCallback(async () => {
//     try {
//       const response = await axios.get(`${API_BASE_URL}/count`);
//       setCount(response.data.count);
//     } catch (error) {
//       console.error('Error fetching count:', error);
//     }
//   }, [API_BASE_URL]);

//   useEffect(() => {
//     fetchCount();
//   }, [fetchCount]);

//   const incrementCount = async () => {
//     try {
//       const response = await axios.post(`${API_BASE_URL}/increment`);
//       setCount(response.data.count);
//     } catch (error) {
//       console.error('Error incrementing count:', error);
//     }
//   };

//   return (
//     <div style={{ textAlign: "center", marginTop: "50px" }}>
//       <h1>Welcome to the page</h1>
//       <button className="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm px-4 py-2 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800" onClick={incrementCount}>Press me</button>
//       <p>You have pressed the button {count} times.</p>
//     </div>
//   );
// }

// export default Test;


import React, { useEffect, useState } from 'react';

function Test() {
    const [triangles, setTriangles] = useState([]);

    useEffect(() => {
        async function fetchMouseData() {
            try {
                const response = await fetch('http://localhost:18080/mouse');
                const data = await response.json();
                setTriangles(data.triangles);
            } catch (error) {
                console.error('Error fetching mouse data:', error);
            }
        }
        fetchMouseData();
    }, []);

    return (
        <svg width="500" height="500" viewBox="-1 -1 2 2" xmlns="http://www.w3.org/2000/svg">
            {triangles.map((triangle, index) => (
                <polygon
                    key={index}
                    points={`${triangle.p1.x},${triangle.p1.y} ${triangle.p2.x},${triangle.p2.y} ${triangle.p3.x},${triangle.p3.y}`}
                    fill={`rgba(${triangle.p1.color[0]}, ${triangle.p1.color[1]}, ${triangle.p1.color[2]}, ${triangle.p1.alpha / 255})`}
                />
            ))}
        </svg>
    );
}

export default Test;
