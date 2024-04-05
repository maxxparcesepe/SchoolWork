from PIL import Image, ImageDraw
import numpy as np
import random 


def generate_art(width, height, num_shapes):
    # Create a blank white canvas
    canvas = Image.new("RGB", (width, height), "white")
    draw = ImageDraw.Draw(canvas)

    for _ in range(num_shapes):

        #Gnerate random shape 
        shape_type = random.choice(["rectangle", "ellipse"])

        # Generate random color
        color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))

        # Generate random position and size
        position = (random.randint(0, width), random.randint(0, height))
        size = (random.randint(10, 100), random.randint(10, 100))

        # Draw the shape on the canvas
        if shape_type == "rectangle":
            draw.rectangle([position, (position[0] + size[0], position[1] + size[1])], fill=color)
        elif shape_type == "ellipse":
            draw.ellipse([position, (position[0] + size[0], position[1] + size[1])], fill=color)
        elif shape_type == "triangle":
            # Define the points of the triangle
            points = [
                position,
                (position[0] + size[0], position[1] + size[1]),
                (position[0] - size[0], position[1] + size[1])
            ]
            draw.polygon(points, fill=color)
        elif shape_type == "line":
            # Define the start and end points of the line
            end_position = (position[0] + size[0], position[1] + size[1])
            draw.line([position, end_position], fill=color, width=3)

    return canvas

if __name__ == "__main__":
    # Set the dimensions of the canvas
    canvas_width = 800
    canvas_height = 600

    # Get user input for the number of shapes
    num_shapes = int(input("Enter the number of shapes: "))

    # Generate art based on user input
    generated_art = generate_art(canvas_width, canvas_height, num_shapes)

    # Save or display the generated art
    generated_art.save("user_generated_art.png")
    generated_art.show()
