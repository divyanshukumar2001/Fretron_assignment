# INITIAL APPROACH -->
# In this we had to draw a graph of the flight routes such that no routes are intersecting. So I knew that Python can be used to draw such graph but I dont know python too much so I tried to learn about how to draw graphs in python ie using matplotlib I read a few articles on it and tried to draw the graph using chat gpt but was unable to come with desired output

# REFERENCE
# https://www.w3schools.com/python/matplotlib_intro.asp
# chatgpt


import matplotlib.pyplot as plt

# Define the coordinates for each flight
flight1 = [(1,1), (2,2), (3,3)]
flight2 = [(1,1), (2,4), (3,2)]
flight3 = [(1,1), (4,2), (3,4)]

# Function to plot flight paths
def plot_flight_path(ax, coordinates, label):
    x, y = zip(*coordinates)
    ax.plot(x, y, marker='o', label=label)

# Create a figure and axis for plotting
fig, ax = plt.subplots()

# Plot each flight path
plot_flight_path(ax, flight1, 'Flight 1')
plot_flight_path(ax, flight2, 'Flight 2')
plot_flight_path(ax, flight3, 'Flight 3')

# Add labels and title
ax.set_xlabel('X Coordinate')
ax.set_ylabel('Y Coordinate')
ax.set_title('Flight Paths')
ax.legend()

# Show the plot
plt.grid(True)
plt.show()
