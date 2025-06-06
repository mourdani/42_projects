import React, {useEffect, useState} from "react";

const LoadingDots: React.FC = () => {
    const [dots, setDots] = useState('');

    useEffect(() => {
        const intervalId = setInterval(() => {
            setDots(prevDots => {
                if (prevDots.length === 3) {
                    return '';
                } else {
                    return prevDots + '.';
                }
            });
        }, 300);

        return () => {
            clearInterval(intervalId);
        };
    }, []);

    return (
        <div>
            <p>{dots}</p>
        </div>
    );
};

export default LoadingDots;