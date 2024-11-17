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
        <div style={{ textAlign: "center", marginTop: "50px" }}>
            <h1>Mouse Visualization</h1>
            <svg width="500" height="500" viewBox="-1 -1 2 2" xmlns="http://www.w3.org/2000/svg">
                {triangles.map((triangle, index) => (
                    <polygon
                        key={index}
                        points={`${triangle.p1.x},${triangle.p1.y} ${triangle.p2.x},${triangle.p2.y} ${triangle.p3.x},${triangle.p3.y}`}
                        fill={`rgba(${triangle.p1.color[0]}, ${triangle.p1.color[1]}, ${triangle.p1.color[2]}, ${triangle.p1.alpha / 255})`}
                    />
                ))}
            </svg>
        </div>
    );
}

export default Test;
