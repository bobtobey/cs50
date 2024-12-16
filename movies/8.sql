SELECT name FROM people AS p
JOIN stars AS s ON p.id = s.person_id
JOIN movies AS m ON s.person_id = m.id WHERE m.title = 'Toy Story';

SELECT title, year FROM movies WHERE title = 'Toy Story';
