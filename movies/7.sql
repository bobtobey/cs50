SELECT title, rating FROM movies AS m JOIN ratings AS r ON m.id = r.movie_id WHERE year = 2010 AND rating IS NOT NULL ORDER BY rating DESC, title ASC;
