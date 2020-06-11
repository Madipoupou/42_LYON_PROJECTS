<?php

require_once("./lib/ft_db_connect.php");

/* Put error string and exit */
function ft_error($error)
{
	echo($error);
	exit();
}

/* Creates empty DB */
function ft_reset_db($link, $name)
{
	$request = "DROP DATABASE IF EXISTS $name;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Suppression BDD impossible\n");
	$request = "CREATE DATABASE $name";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création BDD impossible\n");
}

/* Creates tables */
function ft_create_tables($link)
{
	/* MEMBRE */
	$request = "CREATE TABLE categorie_membre (id_membrecat INT AUTO_INCREMENT NOT NULL,
	nom_membrecat VARCHAR(255),
	PRIMARY KEY (id_membrecat)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE paiement (id_paiement INT AUTO_INCREMENT NOT NULL,
	cb_paiement VARCHAR(255),
	date_exp DATE,
	crypto VARCHAR(10),
	PRIMARY KEY (id_paiement)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE membre (id_membre INT AUTO_INCREMENT NOT NULL,
	nom_membre VARCHAR(255),
	prenom_membre VARCHAR(255),
	mail_membre VARCHAR(255),
	adresse_membre VARCHAR(255),
	tel_membre VARCHAR(255),
	pwd_membre VARCHAR(255),
	url_membre TEXT,
	id_membrecat INT,
	id_paiement INT,
	PRIMARY KEY (id_membre)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE commande (id_commande INT AUTO_INCREMENT NOT NULL,
	date_commande DATE,
	en_cours BOOLEAN,
	id_membre INT,
	PRIMARY KEY (id_commande)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE organe (id_organe INT AUTO_INCREMENT NOT NULL,
	prix_organe FLOAT,
	qualite_organe VARCHAR(10),
	commentaire_organe VARCHAR(255),
	stock INT,
	id_commande INT,
	id_orgcat INT,
	id_loc INT,
	id_prop INT,
	PRIMARY KEY (id_organe)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE categorie_organe (id_orgcat INT AUTO_INCREMENT NOT NULL,
	nom_orgcat VARCHAR(255),
	PRIMARY KEY (id_orgcat)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE localisation (id_loc INT AUTO_INCREMENT NOT NULL,
	lat_loc FLOAT,
	lng_loc FLOAT,
	acc_loc INT,
	PRIMARY KEY (id_loc)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* MEMBRE */
	$request = "CREATE TABLE proprietaire (id_prop INT AUTO_INCREMENT NOT NULL,
	nom_prop VARCHAR(255),
	prenom_prop VARCHAR(255),
	age_prop INT,
	commentaire_prop TEXT,
	login_prop VARCHAR(255),
	url_prop TEXT,
	PRIMARY KEY (id_prop)) ENGINE=InnoDB;";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	/* FOREIGN KEYS */
	$request = "ALTER TABLE membre ADD CONSTRAINT FK_membre_id_membrecat FOREIGN KEY (id_membrecat) REFERENCES categorie_membre (id_membrecat);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	$request = "ALTER TABLE membre ADD CONSTRAINT FK_membre_id_paiement FOREIGN KEY (id_paiement) REFERENCES paiement (id_paiement);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	$request = "ALTER TABLE commande ADD CONSTRAINT FK_commande_id_membre FOREIGN KEY (id_membre) REFERENCES membre (id_membre);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	$request = "ALTER TABLE organe ADD CONSTRAINT FK_organe_commande_id_commande FOREIGN KEY (id_commande) REFERENCES commande (id_commande);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	$request = "ALTER TABLE organe ADD CONSTRAINT FK_organe_id_orgcat FOREIGN KEY (id_orgcat) REFERENCES categorie_organe (id_orgcat);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	$request = "ALTER TABLE organe ADD CONSTRAINT FK_organe_id_loc FOREIGN KEY (id_loc) REFERENCES localisation (id_loc);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
	$request = "ALTER TABLE organe ADD CONSTRAINT FK_organe_id_prop FOREIGN KEY (id_prop) REFERENCES proprietaire (id_prop);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Création de table impossible\n");
}

/* Inserts the starting data in DB */
function ft_insert_data($link)
{
	$request = "INSERT INTO categorie_membre (nom_membrecat)
	VALUES
		('admin'),
		('client');";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
	$request = "INSERT INTO categorie_organe (nom_orgcat)
	VALUES
		('coeur'),
		('foie'),
		('reins'),
		('cerveau'),
		('estomac'),
		('intestins'),
		('poumons');";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
	$request = "INSERT INTO paiement (cb_paiement, date_exp, crypto)
	VALUES
		('4444111144442222', '2019-12-01', '111'),
		('4444222255553333', '2021-06-01', '123'),
		('4444333366664444', '2020-05-01', '456'),
		('4444444477775555', '2023-11-01', '780');";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
	$request = "INSERT INTO membre (nom_membre, prenom_membre, mail_membre, pwd_membre, url_membre, id_membrecat, id_paiement)
	VALUES
		('De-La-Mata', 'Juan', 'jm@gmail.com', '42ed01fd97ca7009d5d0615fa777f3e68720e2d89b8b2408437150314ef536c8bba486b39f9758d6c2eafd29b2294ef690d0a189d86a9fbe02150bbc9741ec56', 'https://cdn.intra.42.fr/users/medium_jde-la-m.JPG', 1, NULL),
		('Hottinger', 'Madric', 'mh@gmail.com', '42ed01fd97ca7009d5d0615fa777f3e68720e2d89b8b2408437150314ef536c8bba486b39f9758d6c2eafd29b2294ef690d0a189d86a9fbe02150bbc9741ec56', 'https://cdn.intra.42.fr/users/medium_mhotting.JPG', 1, NULL),
		('Peroulakis', 'Timothée', 'tp@gmail.com', '42ed01fd97ca7009d5d0615fa777f3e68720e2d89b8b2408437150314ef536c8bba486b39f9758d6c2eafd29b2294ef690d0a189d86a9fbe02150bbc9741ec56', 'https://cdn.intra.42.fr/users/medium_tiperoul.JPG', 2, 1),
		('Rambonona', 'Kévin', 'kr@gmail.com', '42ed01fd97ca7009d5d0615fa777f3e68720e2d89b8b2408437150314ef536c8bba486b39f9758d6c2eafd29b2294ef690d0a189d86a9fbe02150bbc9741ec56', 'https://cdn.intra.42.fr/users/medium_krambono.JPG', 2, 2),
		('Foucher', 'Simon', 'sf@gmail.com', '42ed01fd97ca7009d5d0615fa777f3e68720e2d89b8b2408437150314ef536c8bba486b39f9758d6c2eafd29b2294ef690d0a189d86a9fbe02150bbc9741ec56', 'https://cdn.intra.42.fr/users/medium_sifouche.JPGy', 2, 3);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
	$request = "INSERT INTO commande (date_commande, en_cours, id_membre)
	VALUES
		(NOW(), false, 2),
		('2018-01-26', false, 3),
		('2018-01-27', false, 4),
		('2018-01-28', false, 5),
		('2018-01-29', false, 3),
		('2018-12-30', false, 3),
		('2019-01-25', false, 4),
		('2016-05-22', false, 4),
		('1964-02-11', false, 5),
		('2001-09-25', false, 3),
		(NOW(), false, 2);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
	$request = "INSERT INTO proprietaire (nom_prop, prenom_prop, age_prop, commentaire_prop, login_prop, url_prop)
	VALUES
		('Cotorobai', 'Anastasia', 26, 'Jeune femme en pleine santé', 'canastas', 'https://cdn.intra.42.fr/users/medium_sifouche.JPG'),
		('Nathan', 'Plouvier', 20, 'Donneur régulier', 'naplouvi', 'https://cdn.intra.42.fr/users/medium_naplouvi.JPG'),
		('Pierre', 'Magliozzi', 25, NULL,  'pimaglio', 'https://cdn.intra.42.fr/users/medium_pimaglio.JPG'),
		('Hélène', 'Chretien', 50, 'Fumeuse invétérée', 'hchretie', 'https://cdn.intra.42.fr/users/medium_hchretie.JPG'),
		('Antoine', 'Delrieux', 23, 'Jeune cadre dynamique', 'antdelri', 'https://cdn.intra.42.fr/users/medium_antdelri.JPG'),
		('Jérome' , 'De Mourgue', 53, 'Homme assumant sa part de féminité', 'jde-mour', 'https://cdn.intra.42.fr/users/medium_jde-mour.JPG'),
		('Saïd', 'Chebbal', 51, NULL, 'schebbal', 'https://cdn.intra.42.fr/users/medium_schebbal.JPG'),
		('Alain', 'Ennaji', 50, NULL, 'aennaji', 'https://cdn.intra.42.fr/users/medium_aennaji.JPG'),
		('Audric', 'Rolland', 24, NULL, 'aurollan', 'https://cdn.intra.42.fr/users/medium_aurollan.JPG'),
		('Anthony', 'Razanajatovo', 43, NULL, 'arazanaj', 'https://cdn.intra.42.fr/users/medium_arazanaj.JPG'),
		('Benjamin', 'Fuhro', 32, NULL, 'befuhro', 'https://cdn.intra.42.fr/users/medium_befuhro.JPG');";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
	$request = "INSERT INTO organe (prix_organe, qualite_organe, commentaire_organe, stock, id_commande, id_orgcat, id_loc, id_prop)
	VALUES
		(5299.00, 'B-', 'Poumons de fumeur, bas de gamme', 1, NULL, 7, NULL, 4),
		(6000.00, 'B+', 'Qualité correcte', 1, NULL, 3, NULL, 1),
		(29999.00, 'A++', 'Appartient à un génie', 1, NULL, 4, NULL, 5),
		(8999.00, 'A', 'Très bonne qualité', 1, NULL, 7, NULL, 11),
		(2100.00, 'A+', 'Digestion facile', 1, NULL, 6, NULL, 10),
		(4000.00, 'A', 'Plus de maux de ventre', 1, NULL, 5, NULL, 2),
		(11000.00, 'C-', 'Moyen, un peu épuisé', 1, NULL, 4, NULL, 7),
		(5800.00, 'B', 'Un peu alcolisé mais fonctionnel', 2, NULL, 6, NULL, 3),
		(14000.00, 'B', 'Crises cardiaques rares', 1, NULL, 1, NULL, 1);";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
		ft_error("Erreur - Insertion de données impossible\n");
}


/*********************
 *        MAIN       *
 ********************/
$link = ft_db_connect("");
if (!$link)
	exit();
$name = "lifeshop";
ft_reset_db($link, $name);
$link = ft_db_connect($name);
mysqli_set_charset($link, "utf8");
ft_create_tables($link);
ft_insert_data($link);
$_SESSION["installed"] = true;

?>
