-- use the first WHERE clause to check for actor 1 and use a 2nd WHERE clause to check for actress 2
SELECT title FROM movies AS m
WHERE m.id IN (Select movie_id FROM stars AS s JOIN people AS p1 ON s.person_id = p1.id WHERE name = 'Bradley Cooper')
AND m.id IN (Select movie_id FROM stars AS s JOIN people AS p1 ON s.person_id = p1.id WHERE name = 'Jennifer Lawrence');
