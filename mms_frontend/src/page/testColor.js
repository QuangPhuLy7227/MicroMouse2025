import React, { useState, useEffect } from "react";
import axios from "axios";

const ColorPage = () => {
    const [colors, setColors] = useState({
        tileBaseColor: "",
        tileWallColor: "",
        mouseBodyColor: "",
        mouseWheelColor: "",
        tileWallIsSetColor: "",
        tileWallNotSetAlpha: 0
    });

    useEffect(() => {
        // Fetch default colors from the backend
        axios.get(`${process.env.REACT_APP_API_URL}/api/getColors`)
            .then((response) => setColors(response.data))
            .catch((error) => console.error(error));
        console.log(colors);
    }, []);

    const handleChange = (e) => {
        const { name, value } = e.target;
        setColors({ ...colors, [name]: value });
    };

    const handleSave = () => {
        // Send updated colors to the backend
        axios.post("/api/setColors", colors)
            .then(() => alert("Colors updated successfully!"))
            .catch((error) => console.error(error));
    };

    return (
        <div className="color-page">
            <h1>Update Colors</h1>
            <div>
                <label>Tile Base Color:</label>
                <input type="text" name="tileBaseColor" value={colors.tileBaseColor} onChange={handleChange} />
            </div>
            <div>
                <label>Tile Wall Color:</label>
                <input type="text" name="tileWallColor" value={colors.tileWallColor} onChange={handleChange} />
            </div>
            <div>
                <label>Mouse Body Color:</label>
                <input type="text" name="mouseBodyColor" value={colors.mouseBodyColor} onChange={handleChange} />
            </div>
            <div>
                <label>Mouse Wheel Color:</label>
                <input type="text" name="mouseWheelColor" value={colors.mouseWheelColor} onChange={handleChange} />
            </div>
            <div>
                <label>Tile Wall Is Set Color:</label>
                <input type="text" name="tileWallIsSetColor" value={colors.tileWallIsSetColor} onChange={handleChange} />
            </div>
            <div>
                <label>Tile Wall Not Set Alpha:</label>
                <input type="number" name="tileWallNotSetAlpha" value={colors.tileWallNotSetAlpha} onChange={handleChange} />
            </div>
            <button onClick={handleSave}>Save</button>
        </div>
    );
};

export default ColorPage;
