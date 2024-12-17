-- find id for Kevin Bacon
-- SELECT name, birth, id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958;

-- find movie id's with Kevin Bacon's id
-- SELECT id FROM movies WHERE id IN
-- (SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = 'Kevin Bacon' AND birth = 1958);
-- a more efficient and direct way to find movie id's with Kevin Bacon's id
-- SELECT movie_id
-- FROM stars
-- JOIN people ON stars.person_id = people.id
-- WHERE name = 'Kevin Bacon' AND birth = 1958;

-- find people with id's associated with those movie id's
SELECT name FROM people WHERE id IN
(SELECT person_id FROM stars WHERE movie_id IN
(SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE name = 'Kevin Bacon' AND birth = 1958)) AND name != 'Kevin Bacon';
