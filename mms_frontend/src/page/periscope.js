import { useState } from "react";
const Periscope = () => {

  const [isStart, setIsStart] = useState(false);

  return (
    <div className="p-4 bg-gray-900 flex justify-center items-center min-h-screen">
      <div className="grid grid-cols-5 grid-rows-8 gap-2 bg-red-800 p-4 rounded-lg shadow-lg w-[700px] h-[500px] max-w-4xl">
        
        <div className="col-span-4 row-span-8 col-start-1 row-start-1 bg-blue-300 flex items-center justify-center text-gray-800 font-bold text-lg rounded-lg shadow-inner h-100 w-auto">
          This is the maze
        </div>

        <div className="col-span-1 row-span-2 col-start-5 row-start-1 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-green-600 border-b-2 border-r-2 border-green-300 rounded hover:bg-green-500 transition duration-200">
            Connect
          </button>
        </div>

        <div className="col-span-1 row-span-2 col-start-5 row-start-3 flex justify-center">
          <button
            className="w-full py-1 text-xs text-white bg-yellow-600 border-b-2 border-r-2 border-yellow-300 rounded hover:bg-yellow-500 transition duration-200"
            onClick={() => setIsStart(!isStart)}
          >
            {isStart ? "Stop" : "Start"}
          </button>
        </div>


        <div className="col-span-1 row-span-2 col-start-5 row-start-7 flex justify-center">
          <button className="w-full py-1 text-xs text-white bg-red-600 border-b-2 border-r-2 border-red-300 rounded hover:bg-red-500 transition duration-200">
            Something
          </button>
        </div>
      </div>
    </div>
  );
  };
  
  export default Periscope;
  