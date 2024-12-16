SELECT title FROM movies LIMIT 5;

SELECT name, id FROM people WHERE name = 'Chadwick Boseman';

SELECT title, rating FROM movies AS m JOIN ratings AS r ON m.id = r.movie_id
WHERE 
ORDER BY rating DESC LIMIT 5;
