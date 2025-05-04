-- phpMyAdmin SQL Dump
-- version 4.6.6deb5ubuntu0.5
-- https://www.phpmyadmin.net/
--
-- Client :  localhost:3306
-- Généré le :  Mer 11 Mai 2022 à 02:24
-- Version du serveur :  5.7.38-0ubuntu0.18.04.1
-- Version de PHP :  7.2.24-0ubuntu0.18.04.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `ctp_2022_backlog`
--

-- --------------------------------------------------------

--
-- Structure de la table `Caracteristique`
--

CREATE TABLE `Caracteristique` (
  `name` varchar(100) NOT NULL COMMENT 'Attribut name de la caractéristique',
  `label` varchar(200) NOT NULL COMMENT 'Nom (label général) de la caractéristique',
  `type` varchar(30) NOT NULL COMMENT 'Type de champ(s) de la caractéristique'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `Caracteristique`
--

INSERT INTO `Caracteristique` (`name`, `label`, `type`) VALUES
('categorie', 'Catégorie', 'radio'),
('client', 'Client', 'text'),
('commentaire', 'Commentaire', 'textarea'),
('echeance', 'Échéance', 'date'),
('langueAudio', 'Langue audio', 'radio'),
('metascore', 'Score Metacritic (sur 100)', 'number'),
('plateforme', 'Plate-forme', 'select'),
('tempsEstime', 'Temps estimé (en heures)', 'number'),
('tempsPasse', 'Temps passé (en heures)', 'number');

-- --------------------------------------------------------

--
-- Structure de la table `Choix_Caracteristique`
--

CREATE TABLE `Choix_Caracteristique` (
  `name_caracteristique` varchar(100) NOT NULL,
  `value` varchar(100) NOT NULL,
  `label` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `Choix_Caracteristique`
--

INSERT INTO `Choix_Caracteristique` (`name_caracteristique`, `value`, `label`) VALUES
('categorie', 'film', 'Film'),
('categorie', 'jv', 'Jeu vidéo'),
('categorie', 'livre', 'Livre'),
('categorie', 'serie', 'Série télévisée'),
('categorie', 'travail', 'Travail'),
('langueAudio', 'autre', 'Autre'),
('langueAudio', 'de', 'Allemand'),
('langueAudio', 'en', 'Anglais'),
('langueAudio', 'es', 'Espagnol'),
('langueAudio', 'fr', 'Français'),
('langueAudio', 'jp', 'Japonais'),
('langueAudio', 'muet', 'Muet'),
('plateforme', 'gb', 'Game Boy'),
('plateforme', 'pc', 'PC'),
('plateforme', 'switch', 'Nintendo Switch'),
('plateforme', 'tel', 'Smartphone');

-- --------------------------------------------------------

--
-- Structure de la table `Tache`
--

CREATE TABLE `Tache` (
  `id` int(11) NOT NULL COMMENT 'Identifiant interne unique de l''élément',
  `nom` varchar(200) NOT NULL COMMENT 'Nom ou titre de l''élément',
  `statut` int(11) NOT NULL DEFAULT '0' COMMENT 'Statut de l''élément : non commencé (0), commencé (1), terminé (2) ou abandonné (3)'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `Tache`
--

INSERT INTO `Tache` (`id`, `nom`, `statut`) VALUES
(1, 'Outer Wilds', 2),
(2, 'Réviser pour le le CTP de Web', 2),
(3, 'L\'Homme des jeux', 1),
(4, 'L\'Armée des douze singes', 0),
(5, 'Game of Thrones', 3);

-- --------------------------------------------------------

--
-- Structure de la table `Valeur`
--

CREATE TABLE `Valeur` (
  `name_caracteristique` varchar(100) NOT NULL,
  `id_tache` int(11) NOT NULL,
  `valeur` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `Valeur`
--

INSERT INTO `Valeur` (`name_caracteristique`, `id_tache`, `valeur`) VALUES
('categorie', 1, 'jv'),
('categorie', 2, 'travail'),
('categorie', 3, 'livre'),
('commentaire', 3, 'L\'Homme des jeux (titre original: The Player of Games) est un roman de science-fiction de l\'écrivain écossais Iain M. Banks. Cette œuvre publiée pour la première fois en 1988 (et en 1992 pour la traduction française) peut être considérée comme un space opera. \r\nSource : Wikipédia'),
('echeance', 2, '2022-05-10'),
('plateforme', 1, 'pc'),
('tempsEstime', 1, '21'),
('tempsPasse', 1, '22'),
('tempsPasse', 2, '9');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `Caracteristique`
--
ALTER TABLE `Caracteristique`
  ADD PRIMARY KEY (`name`);

--
-- Index pour la table `Choix_Caracteristique`
--
ALTER TABLE `Choix_Caracteristique`
  ADD PRIMARY KEY (`name_caracteristique`,`value`);

--
-- Index pour la table `Tache`
--
ALTER TABLE `Tache`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `Valeur`
--
ALTER TABLE `Valeur`
  ADD PRIMARY KEY (`name_caracteristique`,`id_tache`),
  ADD KEY `fk_element` (`id_tache`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `Tache`
--
ALTER TABLE `Tache`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Identifiant interne unique de l''élément', AUTO_INCREMENT=6;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `Choix_Caracteristique`
--
ALTER TABLE `Choix_Caracteristique`
  ADD CONSTRAINT `fk_valeur_caracteristique` FOREIGN KEY (`name_caracteristique`) REFERENCES `Caracteristique` (`name`);

--
-- Contraintes pour la table `Valeur`
--
ALTER TABLE `Valeur`
  ADD CONSTRAINT `fk_caracteristique` FOREIGN KEY (`name_caracteristique`) REFERENCES `Caracteristique` (`name`),
  ADD CONSTRAINT `fk_element` FOREIGN KEY (`id_tache`) REFERENCES `Tache` (`id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
