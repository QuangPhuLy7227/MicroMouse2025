# Use the official Ubuntu image
FROM ubuntu:20.04

# Set environment variables to make apt-get non-interactive
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    libboost-all-dev \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy the application source code
COPY . .

# Build the application
RUN g++ -std=c++17 main.cpp -I./Crow/include -lpthread -o app

# Expose the port
EXPOSE 18080

# Run the application
CMD ["./app"]
