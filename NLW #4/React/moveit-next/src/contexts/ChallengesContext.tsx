import { createContext, useState, ReactNode } from 'react';
import challenges from '../../challenges.json';

interface Challenge{
    type: 'body' | 'eye';
    description: string;
    amount: number;
}

interface ChallengesContextData{
    level: number;
    currentExperience: number;
    experienceToNextLevel: number;
    challengesCompleted: number;
    activeChallenger: Challenge;
    levelUp: () => void;
    startNewChallenge: () => void;
    resetChallenge: () => void;
}

interface ChallengesProviderProps{
    children: ReactNode;
}

export const ChallengesContext = createContext({} as ChallengesContextData);

export function ChallengesProvider({children}:ChallengesProviderProps) {
    const [level, setLevel] = useState(0);
    const [currentExperience, setCurrentExperience] = useState(0);
    const [challengesCompleted, setChallengesCompleted] = useState(0);
    

    const [activeChallenger, setActiveChallenger] = useState(null);

    const experienceToNextLevel = Math.pow((level + 1) * 4,2);

    function levelUp(){
        setLevel(level + 1);
    }

    function startNewChallenge(){
        const randomChallengeIndex = Math.floor(Math.random() * challenges.length);
        const challenge = challenges[randomChallengeIndex];
        setActiveChallenger(challenge);
    }

    function resetChallenge(){
        setActiveChallenger(null);
    }

    return(
        <ChallengesContext.Provider 
            value ={{
                level,
                currentExperience, 
                experienceToNextLevel,
                challengesCompleted,
                levelUp,
                startNewChallenge, 
                activeChallenger,
                resetChallenge
            }}
        >
            {children}
        </ChallengesContext.Provider>
    )
}
