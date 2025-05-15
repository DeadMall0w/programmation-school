-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mer. 24 avr. 2024 à 16:37
-- Version du serveur : 10.6.16-MariaDB-0ubuntu0.22.04.1
-- Version de PHP : 8.1.2-1ubuntu2.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `Web1_CTP_Backend_2024_H2iit`
--

-- --------------------------------------------------------

--
-- Structure de la table `Composition_Cycles`
--

CREATE TABLE `Composition_Cycles` (
  `id` int(11) NOT NULL,
  `idCycle` int(11) NOT NULL,
  `idExercice` int(11) NOT NULL,
  `ordre` int(11) NOT NULL,
  `duree` int(11) DEFAULT NULL,
  `repetitions` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `Composition_Cycles`
--

INSERT INTO `Composition_Cycles` (`id`, `idCycle`, `idExercice`, `ordre`, `duree`, `repetitions`) VALUES
(1, 1, 1, 1, 20, NULL),
(2, 1, 2, 2, 20, NULL),
(3, 1, 3, 3, 20, NULL),
(4, 1, 4, 4, 20, NULL),
(8, 1, 5, 5, 30, NULL);

-- --------------------------------------------------------

--
-- Structure de la table `Cycles`
--

CREATE TABLE `Cycles` (
  `id` int(11) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `description` text NOT NULL,
  `idCoach` int(11) NOT NULL,
  `repetitions` int(11) NOT NULL,
  `reposEntreCycles` int(11) NOT NULL,
  `reposEntreExercices` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `Cycles`
--

INSERT INTO `Cycles` (`id`, `nom`, `description`, `idCoach`, `repetitions`, `reposEntreCycles`, `reposEntreExercices`) VALUES
(1, 'tabata', 'Exos de remise en forme', 1, 2, 60, 20);

-- --------------------------------------------------------

--
-- Structure de la table `Exercices`
--

CREATE TABLE `Exercices` (
  `id` int(11) NOT NULL,
  `nom` varchar(100) NOT NULL,
  `description` text DEFAULT NULL,
  `idCoach` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `Exercices`
--

INSERT INTO `Exercices` (`id`, `nom`, `description`, `idCoach`) VALUES
(1, 'Pompes', NULL, 1),
(2, 'Tractions', NULL, 1),
(3, 'Dips', 'Doubles barres', 1),
(4, 'Squats', 'Flexion sur jambes', 1),
(5, 'Burpees', NULL, 1),
(6, 'Développé couché', NULL, 2),
(7, 'Presse à cuisses', NULL, 2);

-- --------------------------------------------------------

--
-- Structure de la table `Users`
--

CREATE TABLE `Users` (
  `id` int(11) NOT NULL,
  `pseudo` varchar(100) NOT NULL,
  `pass` varchar(100) NOT NULL,
  `role` varchar(20) NOT NULL DEFAULT 'athlete' COMMENT 'coach, athlete, admin'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `Users`
--

INSERT INTO `Users` (`id`, `pseudo`, `pass`, `role`) VALUES
(1, 'tom', 'web', 'admin'),
(2, 'max', 'bdd', 'coach'),
(3, 'toto', 'toto', 'athlete');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Composition_Cycles`
--
ALTER TABLE `Composition_Cycles`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idCycle` (`idCycle`),
  ADD KEY `idExercice` (`idExercice`);

--
-- Index pour la table `Cycles`
--
ALTER TABLE `Cycles`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idCoach` (`idCoach`);

--
-- Index pour la table `Exercices`
--
ALTER TABLE `Exercices`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idCoach` (`idCoach`);

--
-- Index pour la table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Composition_Cycles`
--
ALTER TABLE `Composition_Cycles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT pour la table `Cycles`
--
ALTER TABLE `Cycles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `Exercices`
--
ALTER TABLE `Exercices`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT pour la table `Users`
--
ALTER TABLE `Users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Composition_Cycles`
--
ALTER TABLE `Composition_Cycles`
  ADD CONSTRAINT `Composition_Cycles_ibfk_1` FOREIGN KEY (`idCycle`) REFERENCES `Cycles` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `Composition_Cycles_ibfk_2` FOREIGN KEY (`idExercice`) REFERENCES `Exercices` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `Cycles`
--
ALTER TABLE `Cycles`
  ADD CONSTRAINT `Cycles_ibfk_1` FOREIGN KEY (`idCoach`) REFERENCES `Users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Contraintes pour la table `Exercices`
--
ALTER TABLE `Exercices`
  ADD CONSTRAINT `Exercices_ibfk_1` FOREIGN KEY (`idCoach`) REFERENCES `Users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
