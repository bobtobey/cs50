SELECT title FROM movies WHERE year = 2010 LIMIT 12;

SELECT rating FROM ratings ORDER BY rating DESC LIMIT 12;

SELECT title AS t, rating AS r FROM movies AS m JOIN ratings ON m.id = r.movie_id LIMIT 10;
