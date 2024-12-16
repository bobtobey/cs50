SELECT title FROM movies WHERE year = 2010 LIMIT 12;

SELECT rating FROM ratings ORDER BY rating DESC LIMIT 12;

SELECT title, rating FROM movies AS m JOIN ratings AS r ON m.id = r.movie_id WHERE year = 2010 ORDER BY rating DESC, title ASC;
