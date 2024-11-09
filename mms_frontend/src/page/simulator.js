import { useState } from "react";

const Simulator = () => {
  const [width, setWidth] = useState("");
  const [height, setHeight] = useState("");

  return (
    <div className="p-4 bg-gray-900 flex justify-center items-center min-h-screen">
      {/* Maze Section */}
      <div className="grid grid-cols-5 grid-rows-8 gap-2 p-4 rounded-lg shadow-lg w-[600px] h-[500px] max-w-4xl">
        <div className="col-start-1 col-span-5 row-start-1 row-span-8 bg-blue-300 flex items-center justify-center text-gray-800 font-bold text-lg rounded-lg shadow-inner">
          Maze
        </div>
      </div>

      <div className="grid grid-cols-11 grid-rows-8 gap-2 bg-red-800 p-4 rounded-lg shadow-lg w-[600px] h-[500px] max-w-4xl">
        {/* Control & Config with Output Terminal */}
        <div className="col-start-1 col-span-5 flex flex-col gap-4">
          <label className="text-white font-semibold text-lg">Control</label>

          {/* Maze Size Inputs */}
          <div className="flex justify-between gap-4">
            <div className="flex flex-col items-start text-sm">
              <input
                type="number"
                className="w-full py-1 px-2 rounded bg-gray-200 text-gray-800 border border-cyan-400 focus:outline-none focus:border-cyan-600"
                value={width}
                onChange={(e) => setWidth(e.target.value)}
                placeholder="Width"
              />
            </div>

            <div className="flex flex-col items-start text-sm">
              <input
                type="number"
                className="w-full py-1 px-2 rounded bg-gray-200 text-gray-800 border border-cyan-400 focus:outline-none focus:border-cyan-600"
                value={height}
                onChange={(e) => setHeight(e.target.value)}
                placeholder="Height"
              />
            </div>
          </div>

          {/* Buttons Section 1 */}
          <div className="flex justify-between">
            <button className="px-3 py-1 text-xs text-white bg-green-600 border-b-2 border-r-2 border-green-300 rounded hover:bg-green-500 transition duration-200">
              Generate
            </button>

            <button className="px-3 py-1 text-xs text-white bg-yellow-600 border-b-2 border-r-2 border-yellow-300 rounded hover:bg-yellow-500 transition duration-200">
              Start/Stop
            </button>

            <button className="px-3 py-1 text-xs text-white bg-purple-600 border-b-2 border-r-2 border-purple-300 rounded hover:bg-purple-500 transition duration-200">
              Start
            </button>

            <button className="px-3 py-1 text-xs text-white bg-red-600 border-b-2 border-r-2 border-red-300 rounded hover:bg-red-500 transition duration-200">
              Reset
            </button>
          </div>

          {/* Buttons Section 2 */}
          <div className="flex justify-between items-center">
            <button className="px-3 py-1 text-xs text-white bg-green-600 border-b-2 border-r-2 border-green-300 rounded hover:bg-green-500 transition duration-200">
              Cancel
            </button>
            <button className="px-3 py-1 text-xs text-white bg-yellow-600 border-b-2 border-r-2 border-yellow-300 rounded hover:bg-yellow-500 transition duration-200">
              Running
            </button>

            {/* Slider Section */}
            <div className="flex flex-col items-start">
              <input
                id="default-range"
                type="range"
                value="50"
                className="w-full h-2 bg-gray-200 rounded-lg appearance-none cursor-pointer dark:bg-gray-700"
              />
            </div>
          </div>
        </div>

        {/* Config Section */}
        <div className="col-start-6 col-span-6 flex flex-col gap-4 ml-7">
          <label className="text-white font-semibold text-lg">Config</label>

          {/* Maze */}
          <div className="flex items-center gap-2 bg-blue-600 px-2 py-1 rounded-lg">
            <label className="text-white text-xs w-1/3">Maze</label>
            <input
              type="text"
              className="w-1/3 py-0.5 px-1 text-xs rounded bg-gray-200 text-gray-800 border border-cyan-400 focus:outline-none focus:border-cyan-600"
            />
            <button className="w-1/3 flex justify-center items-center bg-blue-400 text-white rounded p-1 text-xs">
              <span>🔧</span>
            </button>
          </div>

          {/* Mouse */}
          <div className="flex items-center gap-2 bg-gray-600 px-2 py-1 rounded-lg">
            <label className="text-white text-xs w-1/3">Mouse</label>
            <input
              type="text"
              className="w-1/3 py-0.5 px-1 text-xs rounded bg-gray-200 text-gray-800 border border-cyan-400 focus:outline-none focus:border-cyan-600"
            />
            <button className="w-1/3 flex justify-center items-center bg-gray-400 text-white rounded p-1 text-xs">
              <span>🔧</span>
            </button>
          </div>
        </div>

        {/* Output Terminal */}
        <div className="col-start-1 row-start-4 col-span-11 row-span-6 bg-blue-300 flex items-center justify-center text-gray-800 font-bold text-lg rounded-lg shadow-inner">
          Output Terminal
        </div>
      </div>
    </div>
  );
};

export default Simulator;
