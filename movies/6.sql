SELECT AVG(rating) FROM ratings;

SELECT title, year FROM movies WHERE year = 2012;

SELECT AVG(rating) FROM ratings WHERE rating IN (SELECT year FROM movies WHERE year = 2012);
