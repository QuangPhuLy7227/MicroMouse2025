import { useState } from "react";

const ControlPanel = () => {
  const [isActivated, setIsActivated] = useState(false);

  return (
    <div className="p-4 bg-gray-900 flex justify-center items-center min-h-screen">
      <div className="grid grid-cols-5 grid-rows-8 gap-2 bg-red-800 p-4 rounded-lg shadow-lg w-[700px] h-[500px] max-w-4xl">
        
        {/* Output Terminal */}
        <div className="col-span-4 row-span-8 bg-blue-300 flex items-center justify-center text-gray-800 font-bold text-lg rounded-lg shadow-inner">
          Output Terminal
        </div>

        {/* Sensor Button */}
        <div className="col-span-1 row-span-2 col-start-5 row-start-1 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-green-600 border-b-2 border-r-2 border-green-300 rounded hover:bg-green-500 transition duration-200">
            Sensor
          </button>
        </div>

        {/* Movement Panel */}
        <div className="col-span-1 row-span-4 col-start-5 row-start-3 flex flex-col items-center justify-center space-y-2">
          <h3 className="text-gray-200 text-xs font-semibold mb-2">Movement</h3>

          {/* Arrow Buttons - Aligned in a directional pad format */}
          <div className="flex flex-col items-center">
            {/* Up Button */}
            <button className="w-12 h-12 bg-blue-600 text-white rounded-full hover:bg-blue-500 mb-2">
              ↑
            </button>

            <div className="flex space-x-2">
              {/* Left Button */}
              <button className="w-12 h-12 bg-blue-600 text-white rounded-full hover:bg-blue-500">
                ←
              </button>

              {/* Right Button */}
              <button className="w-12 h-12 bg-blue-600 text-white rounded-full hover:bg-blue-500">
                →
              </button>
            </div>

            {/* Down Button */}
            <button className="w-12 h-12 bg-blue-600 text-white rounded-full hover:bg-blue-500 mt-2">
              ↓
            </button>
          </div>
        </div>

        {/* Related Function Button */}
        <div className="col-span-1 row-span-2 col-start-5 row-start-7 flex justify-center">
          <button className="w-full py-2 text-xs text-white bg-purple-600 border-b-2 border-r-2 border-purple-300 rounded hover:bg-purple-500 transition duration-200">
            Related Function
          </button>
        </div>
      </div>
    </div>
  );
};

export default ControlPanel;
