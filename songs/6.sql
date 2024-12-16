SELECT name, artist_id FROM songs WHERE artist_id IN (SELECT id, name FROM artists WHERE artists = 'Post Malone' LIMIT 10);

SELECT name, id FROM artists WHERE name = 'Post Malone';
