from PIL import Image, ImageFilter

before = Image.open("courtyard.bmp")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("outedges.bmp")
