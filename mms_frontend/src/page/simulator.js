import { useState } from "react";

const Simulator = () => {
  const [width, setWidth] = useState("");
  const [height, setHeight] = useState("");

  return (
    <div className="p-4 bg-gray-900 flex justify-center items-center min-h-screen">
      <div className="grid grid-cols-5 grid-rows-8 gap-2 bg-red-800 p-4 rounded-lg shadow-lg w-[700px] h-[500px] max-w-4xl">
        
        {/* Maze Size Inputs */}
        <div className="col-span-2 flex mb-12 gap-2">
          <div className="flex flex-col items-start text-sm">
            <label className="text-white mb-1">Width:</label>
            <input
              type="number"
              className="w-28 py-1 px-2 rounded bg-gray-200 text-gray-800 border border-cyan-400 focus:outline-none focus:border-cyan-600"
              value={width}
              onChange={(e) => setWidth(e.target.value)}
              placeholder="Width"
            />
          </div>
          <div className="flex flex-col items-start text-sm">
            <label className="text-white mb-1">Height:</label>
            <input
              type="number"
              className="w-28 py-1 px-2 rounded bg-gray-200 text-gray-800 border border-cyan-400 focus:outline-none focus:border-cyan-600"
              value={height}
              onChange={(e) => setHeight(e.target.value)}
              placeholder="Height"
            />
          </div>
        </div>

        {/* Maze Display - Enlarged Size */}
        <div className="col-span-4 row-span-7 col-start-1 row-start-2 bg-blue-300 flex items-center justify-center text-gray-800 font-bold text-lg rounded-lg shadow-inner h-100 w-full">
          This is the maze
        </div>

        {/* Generate Maze Button */}
        <div className="col-span-1 row-span-2 col-start-5 row-start-1 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-green-600 border-b-2 border-r-2 border-green-300 rounded hover:bg-green-500 transition duration-200">
            Generate Maze
          </button>
        </div>

        {/* Start/Stop Animation Button */}
        <div className="col-span-1 row-span-2 col-start-5 row-start-3 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-yellow-600 border-b-2 border-r-2 border-yellow-300 rounded hover:bg-yellow-500 transition duration-200">
            Start/Stop Animation
          </button>
        </div>

        {/* Save Maze Button */}
        <div className="col-span-1 row-span-2 col-start-5 row-start-5 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-purple-600 border-b-2 border-r-2 border-purple-300 rounded hover:bg-purple-500 transition duration-200">
            Save Maze
          </button>
        </div>

        {/* Load Maze Button */}
        <div className="col-span-1 row-span-2 col-start-5 row-start-7 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-red-600 border-b-2 border-r-2 border-red-300 rounded hover:bg-red-500 transition duration-200">
            Load Maze
          </button>
        </div>
      </div>
    </div>
  );
};

export default Simulator;
