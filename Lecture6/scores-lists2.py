# Use an empty list to store user scores and get average
from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)
    # alternate syntax
    # scores = scores + [score]

average = sum(scores) / len(scores)
print(f"Average: {average}")
