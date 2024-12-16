-- find id for Kevin Bacon
SELECT name, birth, id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958;
-- find movies with Kevin Bacon's id
SELECT title, movie_id FROM movies AS m WHERE m.id IN
(SELECT movie_id FROM stars AS s JOIN people ON s.person_id = people.id WHERE name = 'Kevin Bacon' AND birth = 1958);
-- find people with id's associated with those movie id's
